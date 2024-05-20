#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int status = S21_STATUS_CONVERT_OK;
  s21_decimal truncate_src;
  s21_decimal_init(&truncate_src);
  s21_truncate(src, &truncate_src);

  if (!s21_get_bit(src, S21_SIGN_BIT)) {
    s21_decimal compare;
    s21_from_int_to_decimal(S21_MAX_INT, &compare);

    if (s21_is_greater(truncate_src, compare)) {
      status = S21_STATUS_CONVERT_ERROR;
    } else {
      *dst = truncate_src.bits[0];
    }
  } else {
    s21_decimal compare;
    s21_from_int_to_decimal(S21_MIN_INT, &compare);
    if (s21_is_less(truncate_src, compare)) {
      status = S21_STATUS_CONVERT_ERROR;
    } else {
      *dst = -truncate_src.bits[0];
    }
  }

  return status;
}