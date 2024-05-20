#include "../s21_decimal_tests.h"

START_TEST(s21_dec_to_float_test1) {
  float x = 0.0000001f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_float_test2) {
  float x = 123.456f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_float_test3) {
  float x = 99.99f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_float_test4) {
  float x = 1023.16f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_float_test5) {
  float x = 1.843627f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_float_test6) {
  float x = 1.243f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_float_test7) {
  float x = 876.001f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_float_test8) {
  ;
  s21_decimal d;
  s21_decimal_init(&d);

  s21_set_bit(&d, 1, 32);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(4294967296, result);
}
END_TEST

START_TEST(s21_dec_to_float_test9) {
  ;
  s21_decimal d;
  s21_decimal_init(&d);

  s21_set_bit(&d, 1, 32);
  s21_set_bit(&d, 1, 10);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(4294968320, result);
}
END_TEST

START_TEST(s21_dec_to_float_test10) {
  ;
  float x = 0.0000005f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_float_test11) {
  ;
  float x = S21_MIN_DECIMAL;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_float_test12) {
  ;
  s21_decimal d;
  d.bits[0] = 4294967295;
  d.bits[1] = 4294967295;
  d.bits[2] = 4294967295;

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(S21_MAX_DECIMAL, result);
}
END_TEST

START_TEST(s21_dec_to_float_test13) {
  ;
  float x = -0.0000002555f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_float_test14) {
  ;
  float x = -10.2555f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(x, result);
}
END_TEST

START_TEST(s21_dec_to_float_test15) {
  ;
  float x = -99.99f;
  s21_decimal d;
  s21_from_float_to_decimal(x, &d);

  float result = 0;
  ck_assert_int_eq(0, s21_from_decimal_to_float(d, &result));
  ck_assert_float_eq(x, result);
}
END_TEST

Suite* s21_dec_to_float_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_dec_to_float_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_dec_to_float_test1);
  tcase_add_test(tc_core, s21_dec_to_float_test2);
  tcase_add_test(tc_core, s21_dec_to_float_test3);
  tcase_add_test(tc_core, s21_dec_to_float_test4);
  tcase_add_test(tc_core, s21_dec_to_float_test5);
  tcase_add_test(tc_core, s21_dec_to_float_test6);
  tcase_add_test(tc_core, s21_dec_to_float_test7);
  tcase_add_test(tc_core, s21_dec_to_float_test8);
  tcase_add_test(tc_core, s21_dec_to_float_test9);
  tcase_add_test(tc_core, s21_dec_to_float_test10);
  tcase_add_test(tc_core, s21_dec_to_float_test11);
  tcase_add_test(tc_core, s21_dec_to_float_test12);
  tcase_add_test(tc_core, s21_dec_to_float_test13);
  tcase_add_test(tc_core, s21_dec_to_float_test14);
  tcase_add_test(tc_core, s21_dec_to_float_test15);

  suite_add_tcase(s, tc_core);
  return s;
}