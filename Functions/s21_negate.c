#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int status = 0;

  if (result == NULL || s21_get_degree(value) > 28) {
    status = 1;
  } else {
    int sign = s21_get_bit(value, S21_SIGN_BIT);

    if (sign == 0) {
      s21_set_bit(&value, 1, S21_SIGN_BIT);
      *result = value;
    } else {
      s21_set_bit(&value, 0, S21_SIGN_BIT);
      *result = value;
    }
  }

  return status;
}