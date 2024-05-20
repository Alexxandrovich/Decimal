#include "../s21_decimal.h"

int s21_get_bit(s21_decimal value, unsigned int i) {
  int bit = 0;
  if (i < 32) {
    bit = (value.bits[0] & (1 << i)) >> i;
  } else if (i < 64) {
    bit = (value.bits[1] & (1 << (i - 32))) >> (i - 32);
  } else if (i < 96) {
    bit = (value.bits[2] & (1 << (i - 64))) >> (i - 64);
  } else if (i < 128) {
    bit = (value.bits[3] & (1 << (i - 96))) >> (i - 96);
  } else
    bit = -1;
  return bit;
}

int s21_get_bit_int(long long int value, unsigned int i) {
  int bit = (value & (1LL << i)) >> i;
  return bit;
}

void s21_set_bit(s21_decimal *value, unsigned int bit, unsigned int i) {
  if (!bit) {
    s21_set_bit_zero(value, i);
  } else {
    s21_set_bit_one(value, i);
  }
}

void s21_set_bit_one(s21_decimal *value, unsigned int i) {
  if (i < 32) {
    value->bits[0] = (value->bits[0] | (1 << i));
  } else if (i < 64) {
    value->bits[1] = (value->bits[1] | (1 << (i - 32)));
  } else if (i < 96) {
    value->bits[2] = (value->bits[2] | (1 << (i - 64)));
  } else if (i < 128) {
    value->bits[3] = (value->bits[3] | (1 << (i - 96)));
  }
}

void s21_set_bit_zero(s21_decimal *value, unsigned int i) {
  if (i < 32) {
    value->bits[0] = (value->bits[0] & ~(1 << i));
  } else if (i < 64) {
    value->bits[1] = (value->bits[1] & ~(1 << (i - 32)));
  } else if (i < 96) {
    value->bits[2] = (value->bits[2] & ~(1 << (i - 64)));
  } else if (i < 128) {
    value->bits[3] = (value->bits[3] & ~(1 << (i - 96)));
  }
}

void s21_decimal_init(s21_decimal *value) {
  for (int i = 0; i < 4; i++) {
    value->bits[i] = 0;
  }
}

void s21_decimal_init_int(s21_decimal *value, long long int x) {
  s21_decimal_init(value);
  if (x < 0) {
    x = -x;
    s21_set_bit(value, 1, S21_SIGN_BIT);
  }

  for (int i = 0; i < 64; i++) {
    int bit = s21_get_bit_int(x, i);
    s21_set_bit(value, bit, i);
  }
}

void s21_decimal_init_decimal(s21_decimal *value, s21_decimal src) {
  for (int i = 0; i < 4; i++) {
    value->bits[i] = src.bits[i];
  }
}

int s21_get_degree(s21_decimal value) {
  int mask = 0xFF;
  int degree = (value.bits[3] & (mask << 16)) >> 16;

  return degree;
}

void s21_set_degree(s21_decimal *value, int degree) {
  value->bits[3] = value->bits[3] >> 16;

  for (int i = 0; i < 8; i++) {
    int bit = s21_get_bit_int(degree, i);
    s21_set_bit(value, bit, 96 + i);
  }

  value->bits[3] = value->bits[3] << 16;
}

int s21_div_by_ten(s21_decimal value, s21_decimal *result) {
  unsigned long int buffer = 4294967296U * (value.bits[2] % 10),
                    buffer2 = 4294967296U * ((value.bits[1] + buffer) % 10);
  result->bits[2] = (unsigned long)(value.bits[2]) / 10;
  result->bits[1] = (unsigned long)(value.bits[1] + buffer) / 10;
  result->bits[0] = (unsigned long)(value.bits[0] + buffer2) / 10;
  return (value.bits[0] + buffer2) % 10;
}

void degree_normalization(s21_decimal *value_1, s21_decimal *value_2) {
  int degree1 = s21_get_degree(*value_1);
  int degree2 = s21_get_degree(*value_2);
  if (degree1 != degree2) {
    if (degree1 > degree2) {
      while (degree2 <= 27 && degree1 != degree2 &&
             s21_get_bit(*value_1, 95) != 1 && s21_get_bit(*value_2, 95) != 1) {
        s21_multy_by_shift_decimal_ten(value_2);
        degree2++;
        s21_set_degree(value_2, degree2);
      }
    } else {
      while (degree1 <= 27 && degree1 != degree2 &&
             s21_get_bit(*value_1, 95) != 1 && s21_get_bit(*value_2, 95) != 1) {
        s21_multy_by_shift_decimal_ten(value_1);
        degree1++;
        s21_set_degree(value_1, degree1);
      }
    }
  }

  if (degree1 != degree2) {
    while (degree1 != degree2) {
      if (degree1 > 28) {
        s21_div_by_ten(*value_1, value_1);
        degree1--;
      }
      if (degree2 > 28) {
        s21_div_by_ten(*value_2, value_2);
        degree2--;
      }
    }

    s21_set_degree(value_1, degree1);
    s21_set_degree(value_2, degree2);
  }
}

int s21_define_binary_digits(s21_decimal value) {
  int count = 96;

  for (int i = 95; i >= 0; i--) {
    if (s21_get_bit(value, i) == 1) break;
    count--;
  }

  return count;
}

void s21_init_temp_decimal(s21_decimal *temp, s21_decimal value_1,
                           int count_dig_value_1, int count_dig_value_2) {
  for (int i = 0; i < count_dig_value_2 && (count_dig_value_1 - i) > 0; i++) {
    s21_multy_by_shift_decimal_degree(temp, 1);
    s21_set_bit(temp, s21_get_bit(value_1, count_dig_value_1 - i - 1), 0);
  }
}

int s21_is_zero_decimal(s21_decimal value) {
  return !value.bits[0] && !value.bits[1] && !value.bits[2];
}

int s21_define_count_decimal_digits(s21_decimal d) {
  float f = 0;
  s21_from_decimal_to_float(d, &f);
  int count = 0;
  while (floor(f) > EPS) {
    f /= 10;
    count++;
  }

  return count;
}

int s21_count_sign_digits_int_part(float x) {
  int count = 0;

  while (floor(x) > EPS) {
    x /= 10;
    count++;
  }

  return count;
}

int s21_define_degree(double src) {
  int degree = 0;
  while (floor(src) < EPS) {
    src *= 10;
    degree++;
  }

  return degree;
}

void s21_remove_extra_zeros(long int *number, int pow_degree) {
  int flag = 0;
  int count = 0;
  while (!flag && count < pow_degree) {
    if (*number % 10 == 0) {
      *number /= 10;
    } else
      flag = 1;

    count++;
  }
}

void s21_multy_by_shift_decimal_ten(s21_decimal *src) {
  s21_decimal d;
  s21_decimal_init_decimal(&d, *src);
  s21_decimal d1;
  s21_decimal_init_decimal(&d1, *src);

  s21_multy_by_shift_decimal_degree(&d, 3);
  s21_multy_by_shift_decimal_degree(&d1, 1);

  s21_add_no_drop(d, d1, src);
}

void s21_multy_by_shift_decimal_degree(s21_decimal *src, int degree) {
  int temp_prev = 0;
  int temp_cur = 0;
  for (int i = 0; i < 3; i++) {
    temp_cur = (src->bits[i] & (((int)pow(2, degree) - 1) << (32 - degree))) >>
               (32 - degree);
    src->bits[i] = src->bits[i] << degree;
    if (i > 0) {
      src->bits[i] = src->bits[i] | temp_prev;
    }
    temp_prev = temp_cur;
  }
}

void s21_decimal_init_big_decimal(s21_decimal *value, s21_big_decimal src) {
  for (int i = 0; i < 3; i++) {
    value->bits[i] = src.bits[i];
  }
}

void s21_divide_by_ten_dec(s21_decimal *dec) {
  unsigned long long int initial = 0;
  int rest = 0;
  for (int i = 2; i >= 0; i--) {
    initial = rest * 4294967296U + dec->bits[i];
    dec->bits[i] = initial / 10;
    rest = initial - dec->bits[i] * 10;
  }
}

int s21_last_digit_number_decimal(s21_decimal dec) {
  int last_number = 0;
  for (int i = 0; i < 96; i++) {
    if (i == 0) {
      last_number += s21_get_bit(dec, i) * 1;
    } else if ((i % 4) == 1) {
      last_number += s21_get_bit(dec, i) * 2;
    } else if ((i % 4) == 2) {
      last_number += s21_get_bit(dec, i) * 4;
    } else if ((i % 4) == 3) {
      last_number += s21_get_bit(dec, i) * 8;
    } else if ((i % 4) == 0)
      last_number += s21_get_bit(dec, i) * 6;

    last_number %= 10;
  }
  return last_number;
}

void s21_division_after_different_degrees(s21_big_decimal *result, int n_degree,
                                          int *d) {
  if (n_degree > 0) {
    while (n_degree--) {
      *d += 1;
      if (*d > 29) {
        *d -= 1;
        s21_divide_by_ten_big_dec(result);
      }
    }
  } else if (n_degree < 0) {
    n_degree = -n_degree;
    while (n_degree--) {
      *d -= 1;
      if (*d < 0) {
        s21_multy_by_shift_big_decimal_ten(result);
        *d = 0;
      }
    }
  }
}

void s21_drop_fract_zero(s21_decimal *value) {
  int deg;
  deg = s21_get_degree(*value);
  if (deg > 0) {
    while (deg > 0 && (s21_last_digit_number_decimal(*value) == 0)) {
      s21_divide_by_ten_dec(value);
      deg--;
    }
  }
  s21_set_degree(value, deg);
}

void s21_division_into_column(s21_decimal value_1, s21_decimal value_2,
                              s21_big_decimal *b_dec, int count_dig_value_1,
                              int count_dig_value_2, int *count_n,
                              int *count_decimal_digits, int *degree) {
  int flag = 1;
  s21_decimal temp_div;
  s21_decimal_init(&temp_div);
  s21_decimal temp;
  s21_decimal_init(&temp);

  s21_init_temp_decimal(&temp, value_1, count_dig_value_1, count_dig_value_2);

  int count = count_dig_value_1;
  int flag_count = 1;

  while (flag && *count_n < 102) {
    if (s21_is_greater_or_equal(temp, value_2)) {
      s21_sub(temp, value_2, &temp_div);
      s21_decimal_init_decimal(&temp, temp_div);
      s21_multy_by_shift_decimal_degree(&temp, 1);
      s21_multy_by_shift_big_decimal_degree(b_dec, 1);
      s21_big_decimal_set_bit(b_dec, 1, 0);
      *count_n += 1;
    } else if ((s21_is_zero_decimal(temp) && count < 0)) {
      flag = 0;
    } else {
      s21_multy_by_shift_decimal_degree(&temp, 1);
      s21_multy_by_shift_big_decimal_degree(b_dec, 1);
      s21_big_decimal_set_bit(b_dec, 0, 0);
      *count_n += 1;
    }

    if (flag) {
      if (count == count_dig_value_1) count -= count_dig_value_2;

      if (count > 0) {
        s21_set_bit(&temp, s21_get_bit(value_1, --count), 0);
      } else {
        if (flag_count) {
          s21_decimal temp_decimal;
          s21_decimal_init_big_decimal(&temp_decimal, *b_dec);
          temp_decimal.bits[3] = 0;
          *count_decimal_digits = s21_define_count_decimal_digits(temp_decimal);
          flag_count = 0;
        }
        s21_set_bit(&temp, 0, 0);
        *degree += 1;
        count--;
      }
    }
  }
}

void setbit_pos(s21_decimal *dec, int bit, int pos) {
  int mask = 1 << (pos % 32);
  if (bit == 1) {
    dec->bits[pos / 32] = dec->bits[pos / 32] | mask;
  }
  if (bit == 0) {
    dec->bits[pos / 32] = dec->bits[pos / 32] & ~mask;
  }
}

void setbit_pos_bigdec(big_decimal *dec, int bit, int pos) {
  int mask = 1 << (pos % 32);
  if (bit == 1) {
    dec->bits[pos / 32] = dec->bits[pos / 32] | mask;
  }
  if (bit == 0) {
    dec->bits[pos / 32] = dec->bits[pos / 32] & ~mask;
  }
}

int getbit_pos(s21_decimal dec, int pos) {
  int bit;
  if ((dec.bits[pos / 32] & (1 << pos % 32)) == 0) {
    bit = 0;
  } else
    bit = 1;

  return bit;
}

int getbit_pos_bigdec(big_decimal dec, int pos) {
  int bit;
  if ((dec.bits[pos / 32] & (1 << pos % 32)) == 0) {
    bit = 0;
  } else
    bit = 1;

  return bit;
}

void make_zero_all_bits(s21_decimal *dec) {
  for (int i = 0; i < 128; i++) {
    setbit_pos(dec, 0, i);
  }
}

void make_zero_all_bits_bigdec(big_decimal *dec) {
  for (int i = 0; i < 256; i++) {
    setbit_pos_bigdec(dec, 0, i);
  }
}

void shift_left_bits(s21_decimal *dec) {
  int i = 0;
  int previous = getbit_pos(*dec, i);
  int next = getbit_pos(*dec, i + 1);
  for (; i < 96; i++) {
    next = previous;
    previous = getbit_pos(*dec, i);
    setbit_pos(dec, next, i);
  }
  setbit_pos(dec, 0, 0);
}

void shift_left_bits_bigdec(big_decimal *dec) {
  int i = 0;
  int previous = getbit_pos_bigdec(*dec, i);
  int next = getbit_pos_bigdec(*dec, i + 1);
  for (; i < 192; i++) {
    next = previous;
    previous = getbit_pos_bigdec(*dec, i);
    setbit_pos_bigdec(dec, next, i);
  }
  setbit_pos_bigdec(dec, 0, 0);
}

void convertation_in_big_decimal(s21_decimal dec, big_decimal *big_dec) {
  make_zero_all_bits_bigdec(big_dec);
  for (int i = 0; i < 3; i++) {
    big_dec->bits[i] = dec.bits[i];
  }
  big_dec->scale = dec.bits[3] & SCALE;
  big_dec->sign = dec.bits[3] & MINUS;
}

void convertation_in_decimal(big_decimal big_dec, s21_decimal *dec) {
  make_zero_all_bits(dec);
  for (int i = 0; i < 3; i++) {
    dec->bits[i] = big_dec.bits[i];
  }
  dec->bits[3] = dec->bits[3] | big_dec.scale;
  dec->bits[3] = dec->bits[3] | big_dec.sign;
}

int check_for_zero(s21_decimal dec) {
  int flag = 0;
  if (dec.bits[0] + dec.bits[1] + dec.bits[2]) {
    flag = 1;
  }
  return flag;
}

void divide_by_ten_big_dec(big_decimal *dec) {
  unsigned long long int initial = 0;
  int rest = 0;
  for (int i = 5; i >= 0; i--) {
    initial = rest * 4294967296U + dec->bits[i];
    dec->bits[i] = initial / 10;
    rest = initial - dec->bits[i] * 10;
  }
}

int get_big_degree(big_decimal value) {
  int mask = 0xFF;
  int degree = (value.scale & (mask << 16)) >> 16;

  return degree;
}

int last_digit_number(big_decimal dec) {
  int last_number = 0;
  for (int i = 0; i < 192; i++) {
    if (i == 0) {
      last_number += getbit_pos_bigdec(dec, i) * 1;
    } else if ((i % 4) == 1) {
      last_number += getbit_pos_bigdec(dec, i) * 2;
    } else if ((i % 4) == 2) {
      last_number += getbit_pos_bigdec(dec, i) * 4;
    } else if ((i % 4) == 3) {
      last_number += getbit_pos_bigdec(dec, i) * 8;
    } else if ((i % 4) == 0)
      last_number += getbit_pos_bigdec(dec, i) * 6;

    last_number %= 10;
  }
  return last_number;
}

void add_one_with_big_dec(big_decimal *dec) {
  unsigned int transfer = 1;

  for (int i = 0; i < 6; i++) {
    unsigned int sum = dec->bits[i];
    dec->bits[i] += transfer;
    transfer = (dec->bits[i] < sum);
    if (transfer == 0) break;
  }
}

void daily_addition(big_decimal value_1, big_decimal value_2,
                    big_decimal *result) {
  int tmp = 0;
  int lhs = 0, rhs = 0;
  for (int i = 0; i < 192; i++) {
    lhs = getbit_pos_bigdec(value_1, i);
    rhs = getbit_pos_bigdec(value_2, i);
    if (lhs && rhs && tmp) {
      setbit_pos_bigdec(result, 1, i);
    } else if ((lhs && rhs && (tmp == 0)) || ((lhs || rhs) && tmp)) {
      tmp = 1;
      setbit_pos_bigdec(result, 0, i);
    } else if (lhs || rhs || tmp) {
      setbit_pos_bigdec(result, 1, i);
      tmp = 0;
    }
  }
}

void reduction_number_bigdec(big_decimal *value, int *degree, int *penult_num,
                             int *round_num) {
  int count_no_zero_num = 0;
  if ((value->bits[3] || value->bits[4] || value->bits[5]) != 0) {
    while (((value->bits[3] || value->bits[4] || value->bits[5]) != 0) &&
           *degree > 0) {
      *penult_num = last_digit_number(*value);
      if (*penult_num != 0) {
        *round_num = 1;
        count_no_zero_num++;
      }
      divide_by_ten_big_dec(value);
      (*degree)--;
    }
  }
  if (*degree > 28) {
    while (((value->bits[0] || value->bits[1] || value->bits[2]) != 0) &&
           *degree > 28) {
      *penult_num = last_digit_number(*value);
      if (*penult_num != 0) {
        *round_num = 1;
        count_no_zero_num++;
      }
      divide_by_ten_big_dec(value);
      (*degree)--;
    }
  }
  if (count_no_zero_num == 0 || count_no_zero_num == 1) {
    *round_num = 0;
  }
}

void bank_round(big_decimal *value, int *degree, int *penult_num,
                int *round_num) {
  if (((value->bits[3] || value->bits[4] || value->bits[5]) == 0) &&
      *degree >= 0 && *degree <= 28) {
    if ((*penult_num > 5) || (*penult_num == 5 && *round_num != 0) ||
        (*penult_num == 5 && *round_num == 0 &&
         last_digit_number(*value) % 2 != 0)) {
      add_one_with_big_dec(value);
    }
    if (value->bits[3] != 0) {
      while ((value->bits[3] != 0) && *degree > 0) {
        *penult_num = last_digit_number(*value);
        if (*penult_num != 0) *round_num = 1;
        divide_by_ten_big_dec(value);
        (*degree)--;
      }
      if ((*penult_num > 5) || (*penult_num == 5 && *round_num != 0) ||
          (*penult_num == 5 && *round_num == 0 &&
           last_digit_number(*value) % 2 != 0)) {
        add_one_with_big_dec(value);
      }
    }
  }
}

void s21_div_by_ten_dec(s21_decimal *dec) {
  unsigned long long int initial = 0;
  int rest = 0;
  for (int i = 2; i >= 0; i--) {
    initial = rest * 4294967296U + dec->bits[i];
    dec->bits[i] = initial / 10;
    rest = initial - dec->bits[i] * 10;
  }
}

void drop_fract_zero(s21_decimal *value) {
  int deg;
  deg = s21_get_degree(*value);
  if (deg > 0) {
    while (deg > 0 && (last_digit_number_decimal(*value) == 0)) {
      s21_div_by_ten_dec(value);
      deg--;
    }
  }
  s21_set_degree(value, deg);
}

int last_digit_number_decimal(s21_decimal dec) {
  int last_number = 0;
  for (int i = 0; i < 96; i++) {
    if (i == 0) {
      last_number += getbit_pos(dec, i) * 1;
    } else if ((i % 4) == 1) {
      last_number += getbit_pos(dec, i) * 2;
    } else if ((i % 4) == 2) {
      last_number += getbit_pos(dec, i) * 4;
    } else if ((i % 4) == 3) {
      last_number += getbit_pos(dec, i) * 8;
    } else if ((i % 4) == 0)
      last_number += getbit_pos(dec, i) * 6;

    last_number %= 10;
  }
  return last_number;
}

void add_sign_logic(int sign_value1, int sign_value2, s21_decimal value_1,
                    s21_decimal value_2, s21_decimal *result, int *b_ten) {
  if (sign_value1 == 0 && sign_value2 == 0) {
    s21_add_pos_pos(value_1, value_2, result, b_ten);
  } else if (sign_value1 == 1 && sign_value2 == 1) {
    s21_add_pos_pos(value_1, value_2, result, b_ten);
    s21_set_bit(result, 1, S21_SIGN_BIT);
  } else if (sign_value1 == 1 && sign_value2 == 0) {
    s21_set_bit(&value_1, 0, S21_SIGN_BIT);
    s21_sub(value_2, value_1, result);
  } else if (sign_value1 == 0 && sign_value2 == 1) {
    s21_set_bit(&value_2, 0, S21_SIGN_BIT);
    s21_sub(value_1, value_2, result);
  }
}

int s21_add_no_drop(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  int status = S21_STATUS_OK;
  s21_decimal_init(result);

  degree_normalization(&value_1, &value_2);
  int degree1 = s21_get_degree(value_1);
  int degree2 = s21_get_degree(value_1);

  int b_ten = 0;

  int sign_value1 = s21_get_bit(value_1, S21_SIGN_BIT);
  int sign_value2 = s21_get_bit(value_2, S21_SIGN_BIT);

  add_sign_logic(sign_value1, sign_value2, value_1, value_2, result, &b_ten);

  if (b_ten && (degree1 == 0 || degree2 == 0) &&
      s21_get_bit(*result, S21_SIGN_BIT) == 0) {
    status = S21_STATUS_ERROR_LARGE;
  } else if (b_ten && (degree1 == 0 || degree2 == 0) &&
             s21_get_bit(*result, S21_SIGN_BIT) == 1) {
    status = S21_STATUS_ERROR_SMALL;
  } else if (b_ten && degree1 > 0 && degree2 > 0) {
    s21_div_by_ten(value_1, &value_1);
    degree1--;
    s21_div_by_ten(value_2, &value_2);
    degree2--;
    s21_set_degree(&value_1, degree1);
    s21_set_degree(&value_2, degree2);

    add_sign_logic(sign_value1, sign_value2, value_1, value_2, result, &b_ten);
  }

  s21_set_degree(result, degree1);

  return status;
}

void s21_add_pos_pos(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result, int *b_ten) {
  for (int i = 0; i < 96; i++) {
    if (s21_get_bit(value_1, i) == 1 && s21_get_bit(value_2, i) == 1) {
      if (!*b_ten) {
        s21_set_bit(result, 0, i);
        *b_ten = 1;
      } else {
        s21_set_bit(result, 1, i);
        *b_ten = 1;
      }
    } else if (s21_get_bit(value_1, i) == 0 && s21_get_bit(value_2, i) == 0) {
      if (*b_ten) {
        s21_set_bit(result, 1, i);
        *b_ten = 0;
      }
    } else {
      if (!*b_ten) {
        s21_set_bit(result, 1, i);
      } else {
        s21_set_bit(result, 0, i);
        *b_ten = 1;
      }
    }
  }

  int degree1 = s21_get_degree(value_1);
  s21_set_degree(result, degree1);
}

void s21_sub_pos_pos(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result) {
  for (int i = 0; i < 96; i++) {
    if (s21_get_bit(value_1, i) == 1 && s21_get_bit(value_2, i) == 1) {
      s21_set_bit(result, 0, i);
    } else if (s21_get_bit(value_1, i) == 0 && s21_get_bit(value_2, i) == 0) {
      s21_set_bit(result, 0, i);
    } else if (s21_get_bit(value_1, i) == 1 && s21_get_bit(value_2, i) == 0) {
      s21_set_bit(result, 1, i);
    } else {
      int bit = 0;
      int j = i;

      while (bit != 1) {
        bit = s21_get_bit(value_1, j);
        if (bit == 0) j++;
      }

      s21_set_bit(&value_1, 0, j);

      while (j != i) {
        s21_set_bit(&value_1, 1, j - 1);
        j--;
      }

      if (j == i) s21_set_bit(result, 1, i);
    }
  }
}