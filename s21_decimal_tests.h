#ifndef S21_DECIMAL_TEST_H
#define S21_DECIMAL_TEST_H

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

void s21_Srunner(Suite** suite);
Suite* s21_add_test(void);
Suite* s21_sub_test(void);
Suite* s21_mul_test(void);
Suite* s21_div_test(void);
Suite* s21_is_less_test(void);
Suite* s21_is_less_or_equal_test(void);
Suite* s21_is_greater_test(void);
Suite* s21_is_greater_or_equal_test(void);
Suite* s21_is_equal_test(void);
Suite* s21_not_equal_test(void);
Suite* s21_int_to_dec_test(void);
Suite* s21_float_to_dec_test(void);
Suite* s21_dec_to_int_test(void);
Suite* s21_dec_to_float_test(void);
Suite* s21_floor_test(void);
Suite* s21_round_test(void);
Suite* s21_truncate_test(void);
Suite* s21_negate_test(void);

#endif
