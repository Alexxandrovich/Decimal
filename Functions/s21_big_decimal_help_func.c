#include "../s21_decimal.h"

void s21_big_decimal_init(s21_big_decimal *value) {
  for (int i = 0; i < 8; i++) {
    value->bits[i] = 0;
  }
}

// void s21_big_decimal_init_decimal(s21_big_decimal *value, s21_decimal src) {
//   for (int i = 0; i < 8; i++) {
//     if (i < 4)
//       value->bits[i] = src.bits[i];
//     else
//       value->bits[i] = 0;
//   }

//   value->bits[7] = src.bits[3];
// }

void s21_big_decimal_init_big_decimal(s21_big_decimal *value,
                                      s21_big_decimal src) {
  for (int i = 0; i < 8; i++) {
    value->bits[i] = src.bits[i];
  }
}

void s21_div_by_shift_big_decimal(s21_big_decimal *src) {
  int temp_prev = 0;
  int temp_cur = 0;

  for (int i = 6; i >= 0; i--) {
    temp_cur = src->bits[i] & 1;
    src->bits[i] = src->bits[i] >> 1;
    if (i < 6) {
      src->bits[i] = src->bits[i] | (temp_prev << 31);
    }
    temp_prev = temp_cur;
  }
}

void s21_multy_by_shift_big_decimal_ten(s21_big_decimal *src) {
  s21_big_decimal d;
  s21_big_decimal_init_big_decimal(&d, *src);
  s21_big_decimal d1;
  s21_big_decimal_init_big_decimal(&d1, *src);

  s21_multy_by_shift_big_decimal_degree(&d, 3);
  s21_multy_by_shift_big_decimal_degree(&d1, 1);

  s21_big_decimal_add(d, d1, src);
}

void s21_multy_by_shift_big_decimal_degree(s21_big_decimal *src, int degree) {
  int temp_prev = 0;
  int temp_cur = 0;
  for (int i = 0; i < 7; i++) {
    temp_cur = (src->bits[i] & (((int)pow(2, degree) - 1) << (32 - degree))) >>
               (32 - degree);
    src->bits[i] = src->bits[i] << degree;
    if (i > 0) {
      src->bits[i] = src->bits[i] | temp_prev;
    }
    temp_prev = temp_cur;
  }
}

int s21_big_decimal_get_bit(s21_big_decimal value, unsigned int i) {
  int bit;
  if ((value.bits[i / 32] & (1 << i % 32)) == 0) {
    bit = 0;
  } else
    bit = 1;

  return bit;
}

void s21_big_decimal_set_bit(s21_big_decimal *value, unsigned int bit,
                             unsigned int i) {
  int mask = 1 << (i % 32);
  if (bit == 1) {
    value->bits[i / 32] = value->bits[i / 32] | mask;
  }
  if (bit == 0) {
    value->bits[i / 32] = value->bits[i / 32] & ~mask;
  }
}

void s21_divide_by_ten_big_dec(s21_big_decimal *dec) {
  unsigned long long int initial = 0;
  int rest = 0;
  for (int i = 6; i >= 0; i--) {
    initial = rest * 4294967296U + dec->bits[i];
    dec->bits[i] = initial / 10;
    rest = initial - dec->bits[i] * 10;
  }
}

int s21_getbit_pos_bigdec(s21_big_decimal dec, int pos) {
  int bit;
  if ((dec.bits[pos / 32] & (1 << pos % 32)) == 0) {
    bit = 0;
  } else
    bit = 1;

  return bit;
}

int s21_last_digit_number_big_decimal(s21_big_decimal dec) {
  int last_number = 0;
  for (int i = 0; i < 224; i++) {
    if (i == 0) {
      last_number += s21_getbit_pos_bigdec(dec, i) * 1;
    } else if ((i % 4) == 1) {
      last_number += s21_getbit_pos_bigdec(dec, i) * 2;
    } else if ((i % 4) == 2) {
      last_number += s21_getbit_pos_bigdec(dec, i) * 4;
    } else if ((i % 4) == 3) {
      last_number += s21_getbit_pos_bigdec(dec, i) * 8;
    } else if ((i % 4) == 0)
      last_number += s21_getbit_pos_bigdec(dec, i) * 6;

    last_number %= 10;
  }
  return last_number;
}

void s21_big_decimal_round(s21_big_decimal *b_dec, int *degree) {
  int last_number = s21_last_digit_number_big_decimal(*b_dec);
  s21_divide_by_ten_big_dec(b_dec);
  *degree -= 1;

  if (b_dec->bits[3]) {
    last_number = s21_last_digit_number_big_decimal(*b_dec);
    s21_divide_by_ten_big_dec(b_dec);
    *degree -= 1;
    s21_big_decimal_bank_round(b_dec, last_number);
  } else {
    s21_big_decimal_bank_round(b_dec, last_number);
  }
}

void s21_big_decimal_bank_round(s21_big_decimal *b_dec, int last_number) {
  if (b_dec->bits[0] % 2 == 0) {
    if (last_number > 5) s21_add_one_with_big_dec(b_dec);
  } else {
    if (last_number > 4) s21_add_one_with_big_dec(b_dec);
  }
}

void s21_add_one_with_big_dec(s21_big_decimal *dec) {
  unsigned int transfer = 1;

  for (int i = 0; i < 7; i++) {
    unsigned int sum = dec->bits[i];
    dec->bits[i] += transfer;
    transfer = (dec->bits[i] < sum);
    if (transfer == 0) break;
  }
}

int s21_is_zero_big_decimal(s21_big_decimal value) {
  return !value.bits[0] && !value.bits[1] && !value.bits[2] && !value.bits[3] &&
         !value.bits[4] && !value.bits[6];
}

int s21_big_decimal_add(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result) {
  int status = S21_STATUS_OK;
  int b_ten = 0;
  s21_big_decimal_init(result);
  s21_big_decimal_add_pos_pos(value_1, value_2, result, &b_ten);

  if (b_ten) status = S21_STATUS_ERROR_LARGE;

  return status;
}

void s21_big_decimal_add_pos_pos(s21_big_decimal value_1,
                                 s21_big_decimal value_2,
                                 s21_big_decimal *result, int *b_ten) {
  for (int i = 0; i < 224; i++) {
    if (s21_big_decimal_get_bit(value_1, i) == 1 &&
        s21_big_decimal_get_bit(value_2, i) == 1) {
      if (!*b_ten) {
        s21_big_decimal_set_bit(result, 0, i);
        *b_ten = 1;
      } else {
        s21_big_decimal_set_bit(result, 1, i);
        *b_ten = 1;
      }
    } else if (s21_big_decimal_get_bit(value_1, i) == 0 &&
               s21_big_decimal_get_bit(value_2, i) == 0) {
      if (*b_ten) {
        s21_big_decimal_set_bit(result, 1, i);
        *b_ten = 0;
      }
    } else {
      if (!*b_ten) {
        s21_big_decimal_set_bit(result, 1, i);
      } else {
        s21_big_decimal_set_bit(result, 0, i);
        *b_ten = 1;
      }
    }
  }
}
