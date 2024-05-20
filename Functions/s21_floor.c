#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int status = 0;
  if (result == NULL || s21_get_degree(value) > 28) {
    status = 1;
  } else {
    int degree = s21_get_degree(value);
    int sign = s21_get_bit(value, S21_SIGN_BIT);
    s21_decimal buffer1 = value;
    s21_decimal buffer2;

    if (degree == 0) {
      *result = value;
    } else {
      while (degree > 0) {
        s21_div_by_ten(buffer1, &buffer2);
        buffer1 = buffer2;
        degree--;
      }
      s21_set_degree(&buffer2, degree);
      if (sign == 1) {
        s21_decimal one;
        s21_decimal_init(&one);
        one.bits[0] = 1;
        s21_add(buffer2, one, &buffer2);
        s21_set_bit(&buffer2, 1, S21_SIGN_BIT);
      }
      *result = buffer2;
    }
  }
  return status;
}