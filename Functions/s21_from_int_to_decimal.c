#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int status = S21_STATUS_CONVERT_OK;
  s21_decimal_init(dst);

  if (src == S21_MIN_INT) {
    unsigned int u = -src;
    dst->bits[0] = u;
    s21_set_bit(dst, 1, S21_SIGN_BIT);
  } else {
    if (src < 0) {
      src = -src;
      s21_set_bit(dst, 1, S21_SIGN_BIT);
    }

    dst->bits[0] = src;
  }

  return status;
}
