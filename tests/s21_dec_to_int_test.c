#include "../s21_decimal_tests.h"

START_TEST(s21_dec_to_int_test1) {
  int x = -1;
  s21_decimal d;
  s21_from_int_to_decimal(x, &d);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_int_test2) {
  int x = 12345;
  s21_decimal d;
  s21_from_int_to_decimal(x, &d);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_int_test3) {
  int x = S21_MAX_INT;
  s21_decimal d;
  s21_from_int_to_decimal(x, &d);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_int_test4) {
  int x = S21_MIN_INT;
  s21_decimal d;
  s21_from_int_to_decimal(x, &d);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_int_test5) {
  long int x = 223372036854775807;
  s21_decimal d;
  s21_decimal_init_int(&d, x);

  int result = 0;
  ck_assert_int_eq(1, s21_from_decimal_to_int(d, &result));
}
END_TEST

START_TEST(s21_dec_to_int_test6) {
  long int x = 223372036854775807;
  s21_decimal d;
  s21_decimal_init_int(&d, x);
  s21_set_degree(&d, 10);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(22337203, result);
}
END_TEST

START_TEST(s21_dec_to_int_test7) {
  float x = 0.9f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(s21_dec_to_int_test8) {
  float x = 123.9f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(123, result);
}
END_TEST

START_TEST(s21_dec_to_int_test9) {
  float x = -66678.9f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(-66678, result);
}
END_TEST

START_TEST(s21_dec_to_int_test10) {
  long int x = S21_MAX_INT + 1L;
  s21_decimal d;
  s21_decimal_init_int(&d, x);

  int result = 0;
  ck_assert_int_eq(1, s21_from_decimal_to_int(d, &result));
}
END_TEST

START_TEST(s21_dec_to_int_test11) {
  long int x = S21_MIN_INT - 1L;
  s21_decimal d;
  s21_decimal_init_int(&d, x);

  int result = 0;
  ck_assert_int_eq(1, s21_from_decimal_to_int(d, &result));
}
END_TEST

START_TEST(s21_dec_to_int_test12) {
  long int x = S21_MIN_INT * 10L - 5;
  s21_decimal d;
  s21_decimal_init_int(&d, x);
  s21_set_degree(&d, 1);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(S21_MIN_INT, result);
}
END_TEST

START_TEST(s21_dec_to_int_test13) {
  long int x = S21_MAX_INT * 10L + 3;
  s21_decimal d;
  s21_decimal_init_int(&d, x);
  s21_set_degree(&d, 1);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(S21_MAX_INT, result);
}
END_TEST

START_TEST(s21_dec_to_int_test14) {
  long int x = 111111111111;
  s21_decimal d;
  s21_decimal_init_int(&d, x);
  s21_set_degree(&d, 2);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(1111111111, result);
}
END_TEST

START_TEST(s21_dec_to_int_test15) {
  long int x = -111111111111;
  s21_decimal d;
  s21_decimal_init_int(&d, x);
  s21_set_degree(&d, 2);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(-1111111111, result);
}
END_TEST

START_TEST(s21_dec_to_int_test16) {
  float x = 0.000001f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  int result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_int(d, &result));
  ck_assert_int_eq(0, result);
}
END_TEST

Suite* s21_dec_to_int_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_dec_to_int_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_dec_to_int_test1);
  tcase_add_test(tc_core, s21_dec_to_int_test2);
  tcase_add_test(tc_core, s21_dec_to_int_test3);
  tcase_add_test(tc_core, s21_dec_to_int_test4);
  tcase_add_test(tc_core, s21_dec_to_int_test5);
  tcase_add_test(tc_core, s21_dec_to_int_test6);
  tcase_add_test(tc_core, s21_dec_to_int_test7);
  tcase_add_test(tc_core, s21_dec_to_int_test8);
  tcase_add_test(tc_core, s21_dec_to_int_test9);
  tcase_add_test(tc_core, s21_dec_to_int_test10);
  tcase_add_test(tc_core, s21_dec_to_int_test11);
  tcase_add_test(tc_core, s21_dec_to_int_test12);
  tcase_add_test(tc_core, s21_dec_to_int_test13);
  tcase_add_test(tc_core, s21_dec_to_int_test14);
  tcase_add_test(tc_core, s21_dec_to_int_test15);
  tcase_add_test(tc_core, s21_dec_to_int_test16);

  suite_add_tcase(s, tc_core);
  return s;
}