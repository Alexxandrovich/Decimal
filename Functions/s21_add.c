#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
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

  drop_fract_zero(result);

  return status;
}