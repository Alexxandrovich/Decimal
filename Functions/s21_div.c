#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = S21_STATUS_OK, minus = 0;
  if (s21_is_zero_decimal(value_2)) {
    status = S21_STATUS_ERROR_DIV_BY_ZERO;
  } else if (s21_is_zero_decimal(value_1)) {
    s21_decimal_init(result);
    s21_set_degree(result, 0);
  } else {
    s21_decimal_init(result);
    if (s21_get_bit(value_1, S21_SIGN_BIT)) {
      s21_set_bit(&value_1, 0, S21_SIGN_BIT);
      minus = 1;
    }
    if (s21_get_bit(value_2, S21_SIGN_BIT)) {
      if (minus)
        minus = 0;
      else
        minus = 1;
      s21_set_bit(&value_2, 0, S21_SIGN_BIT);
    }
    int n_degree = s21_get_degree(value_1) - s21_get_degree(value_2);
    s21_set_degree(&value_1, 0);
    s21_set_degree(&value_2, 0);
    int count_dig_value_1 = s21_define_binary_digits(value_1);
    int count_dig_value_2 = s21_define_binary_digits(value_2);
    s21_big_decimal b_dec;
    s21_big_decimal_init(&b_dec);
    int degree = -1, count_n = 0, count_decimal_digits = 0;
    s21_division_into_column(value_1, value_2, &b_dec, count_dig_value_1,
                             count_dig_value_2, &count_n, &count_decimal_digits,
                             &degree);
    int d = 0;
    if (degree > 0) {
      if (count_n == 102)
        d = 29 - count_decimal_digits + 1;
      else if (degree > 28)
        d = 29;
      else
        d = degree;
      for (int i = 0; i < degree; i++) {
        if (i < d) {
          s21_multy_by_shift_big_decimal_ten(&b_dec);
          s21_div_by_shift_big_decimal(&b_dec);
        } else
          s21_div_by_shift_big_decimal(&b_dec);
      }
    }
    s21_division_after_different_degrees(&b_dec, n_degree, &d);
    if (d == 30) {
      s21_divide_by_ten_big_dec(&b_dec);
      d--;
    }
    if (count_n == 102 || d == 29) s21_big_decimal_round(&b_dec, &d);
    if (b_dec.bits[3] || b_dec.bits[4] || b_dec.bits[5]) {
      status = S21_STATUS_ERROR_LARGE;
    } else if (s21_is_zero_big_decimal(b_dec)) {
      status = S21_STATUS_ERROR_SMALL;
      s21_decimal_init_big_decimal(result, b_dec);
      s21_set_degree(result, 0);
    } else {
      s21_decimal_init_big_decimal(result, b_dec);
      s21_set_degree(result, d);
      if (minus) s21_set_bit(result, 1, S21_SIGN_BIT);
      s21_drop_fract_zero(result);
    }
  }
  return status;
}
