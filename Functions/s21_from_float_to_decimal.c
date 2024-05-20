#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = S21_STATUS_CONVERT_OK;
  s21_decimal_init(dst);
  if (fabs(src) > S21_MAX_DECIMAL || isinf(src) || isnan(src)) {
    status = S21_STATUS_CONVERT_ERROR;
  } else if (fabs(src) < S21_MIN_DECIMAL && src != 0) {
    status = S21_STATUS_CONVERT_ERROR;
  } else if (src == 0) {
    status = S21_STATUS_CONVERT_OK;
  } else {
    int flag_minus = 0;
    if (src < 0) {
      src = -src;
      flag_minus = 1;
    }
    int degree = 0;
    int count_sign_digits = s21_count_sign_digits_int_part(src);
    int pow_degree = 7 - count_sign_digits;
    if (!count_sign_digits) {
      degree = s21_define_degree(src);
      pow_degree = 7 + degree - 1;
    }
    double round = 0.5 * pow(10, -pow_degree);
    double xx = src + round;
    degree = s21_define_degree(xx);
    if (pow_degree < 0) {
      int count = -pow_degree;
      long int number = (long int)(xx / pow(10, count));
      s21_decimal_init_int(dst, number);
      s21_set_degree(dst, degree);
      for (int i = 0; i < count; i++) s21_multy_by_shift_decimal_ten(dst);
      if (flag_minus) s21_set_bit(dst, 1, S21_SIGN_BIT);
    } else {
      long int number = (long int)(xx * pow(10, pow_degree));
      long int start = (long int)xx;
      if (pow_degree >= 0) {
        s21_remove_extra_zeros(&number, pow_degree);
        long int m = number;
        while (m > start) {
          degree++;
          m /= 10;
        }
        if (!count_sign_digits) degree--;
      }
      s21_decimal_init_int(dst, number);
      s21_set_degree(dst, degree);
      if (flag_minus) s21_set_bit(dst, 1, S21_SIGN_BIT);
    }
  }
  return status;
}
