#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  big_decimal value_big_dec_1, value_big_dec_2, big_dec_result;
  int res = OK;
  int penultimate_element = 0;
  int round_flag = 0;

  int res_degree;
  res_degree = s21_get_degree(value_1) + s21_get_degree(value_2);
  make_zero_all_bits(result);
  make_zero_all_bits_bigdec(&big_dec_result);
  if (check_for_zero(value_1) && check_for_zero(value_2) &&
      (res_degree <= 86)) {
    convertation_in_big_decimal(value_1, &value_big_dec_1);
    convertation_in_big_decimal(value_2, &value_big_dec_2);
    for (int i = 0; i < 192; i++) {
      if (getbit_pos_bigdec(value_big_dec_2, i) == 1) {
        daily_addition(big_dec_result, value_big_dec_1, &big_dec_result);
      }
      shift_left_bits_bigdec(&value_big_dec_1);
    }
    reduction_number_bigdec(&big_dec_result, &res_degree, &penultimate_element,
                            &round_flag);
    bank_round(&big_dec_result, &res_degree, &penultimate_element, &round_flag);
    if ((big_dec_result.bits[3] || big_dec_result.bits[4] ||
         big_dec_result.bits[5]) != 0) {
      if (value_big_dec_1.sign == value_big_dec_2.sign) {
        res = INF_POS;
      } else
        res = INF_NEG;
    } else {
      convertation_in_decimal(big_dec_result, result);
      s21_set_degree(result, res_degree);
      if (getbit_pos(value_1, 127) == getbit_pos(value_2, 127)) {
        setbit_pos(result, 0, 127);
      } else
        setbit_pos(result, 1, 127);
      drop_fract_zero(result);
    }
  }
  return res;
}