#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result != NULL && s21_get_degree(value) <= 28) {
    *result = value;
    if (s21_get_degree(value)) {
      for (int i = 0; i < s21_get_degree(value); i++) {
        s21_div_by_ten_dec(result);
      }
      s21_set_degree(result, 0);
    }
  } else {
    res = 1;
  }
  return res;
}