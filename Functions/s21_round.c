#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result != NULL && s21_get_degree(value) <= 28) {
    *result = value;
    s21_decimal val_1 = {0};

    s21_decimal val_2 = {0};
    s21_set_bit(&val_2, 1, 0);
    s21_set_bit(&val_2, 1, 2);
    s21_set_degree(&val_2, 1);

    s21_truncate(value, result);
    s21_sub(value, *result, &val_1);
    int i = 0;
    if (s21_is_greater_or_equal(val_1, val_2)) {
      while (s21_get_bit(*result, i) == 1) {
        s21_set_bit(result, 0, i);
        i++;
      }
      s21_set_bit(result, 1, i);
    }
  } else {
    res = 1;
  }

  return res;
}
