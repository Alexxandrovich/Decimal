#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int status = S21_STATUS_CONVERT_OK;
  int degree = s21_get_degree(src);
  *dst = 0;
  for (int i = 0; i < 96; i++) {
    *dst += s21_get_bit(src, i) * pow(2, i);
  }

  *dst /= pow(10, degree);

  if (s21_get_bit(src, S21_SIGN_BIT) == 1) {
    *dst *= -1;
  }

  return status;
}