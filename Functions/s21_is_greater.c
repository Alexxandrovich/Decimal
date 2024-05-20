#include "../s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  degree_normalization(&value_1, &value_2);

  int sign_value1 = s21_get_bit(value_1, S21_SIGN_BIT);
  int sign_value2 = s21_get_bit(value_2, S21_SIGN_BIT);

  if (sign_value1 == 0 && sign_value2 == 1) {
    result = 1;
  } else if (sign_value1 == 1 && sign_value2 == 0) {
    result = 0;
  } else if (sign_value1 == 0 && sign_value2 == 0) {
    for (int i = 95; i >= 0; i--) {
      if (s21_get_bit(value_1, i) == 1 && s21_get_bit(value_2, i) == 0) {
        result = 1;
        break;
      } else if (s21_get_bit(value_1, i) == 0 && s21_get_bit(value_2, i) == 1) {
        result = 0;
        break;
      }
    }
  } else {
    for (int i = 95; i >= 0; i--) {
      if (s21_get_bit(value_1, i) == 1 && s21_get_bit(value_2, i) == 0) {
        result = 0;
        break;
      } else if (s21_get_bit(value_1, i) == 0 && s21_get_bit(value_2, i) == 1) {
        result = 1;
        break;
      }
    }
  }

  if (value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0 &&
      value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
    result = 0;  // +0 == -0
  }

  return result;
}
