#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = S21_STATUS_OK;
  s21_decimal_init(result);

  degree_normalization(&value_1, &value_2);
  int degree1 = s21_get_degree(value_1);
  int status_crutch = 1;

  int sign_value1 = s21_get_bit(value_1, S21_SIGN_BIT);
  int sign_value2 = s21_get_bit(value_2, S21_SIGN_BIT);
  int val1_is_greater = s21_is_greater(value_1, value_2);
  int is_equal = s21_is_equal(value_1, value_2);

  if (is_equal == 0) {
    if (sign_value1 == 0 && sign_value2 == 0) {
      if (val1_is_greater) {
        s21_sub_pos_pos(value_1, value_2, result);
      } else {
        s21_sub_pos_pos(value_2, value_1, result);
        s21_set_bit(result, 1, S21_SIGN_BIT);
      }
    } else if (sign_value1 == 1 && sign_value2 == 1) {
      if (val1_is_greater) {
        s21_sub_pos_pos(value_2, value_1, result);
      } else {
        s21_sub_pos_pos(value_1, value_2, result);
        s21_set_bit(result, 1, S21_SIGN_BIT);
      }
    } else if (sign_value1 == 0 && sign_value2 == 1) {
      s21_set_bit(&value_2, 0, S21_SIGN_BIT);
      status = s21_add(value_1, value_2, result);
    } else if (sign_value1 == 1 && sign_value2 == 0) {
      s21_set_bit(&value_2, 1, S21_SIGN_BIT);
      status = s21_add(value_1, value_2, result);
      status_crutch = 0;
    }
  }
  if (status_crutch) {
    degree1 = s21_get_degree(value_1);
    s21_set_degree(result, degree1);
    drop_fract_zero(result);
  }

  return status;
}
