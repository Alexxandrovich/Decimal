#include "../s21_decimal_tests.h"

START_TEST(s21_int_to_dec_test1) {
  int x = 120;
  s21_decimal d;

  ck_assert_int_eq(0, s21_from_int_to_decimal(x, &d));
  ck_assert_int_eq(x, d.bits[0]);
}
END_TEST

START_TEST(s21_int_to_dec_test2) {
  int x = 120;
  s21_decimal d;

  ck_assert_int_eq(0, s21_from_int_to_decimal(x, &d));
  ck_assert_int_eq(x, d.bits[0]);
}
END_TEST

START_TEST(s21_int_to_dec_test3) {
  int x = 123456789;
  s21_decimal d;

  ck_assert_int_eq(0, s21_from_int_to_decimal(x, &d));
  ck_assert_int_eq(x, d.bits[0]);
  ck_assert_int_eq(0, d.bits[1]);
  ck_assert_int_eq(0, d.bits[2]);
  ck_assert_int_eq(0, d.bits[3]);
}
END_TEST

START_TEST(s21_int_to_dec_test4) {
  int x = -123456789;
  s21_decimal d;

  ck_assert_int_eq(0, s21_from_int_to_decimal(x, &d));
  ck_assert_int_eq(-x, d.bits[0]);
  ck_assert_int_eq(1, s21_get_bit(d, S21_SIGN_BIT));
}
END_TEST

START_TEST(s21_int_to_dec_test5) {
  int x = 1;
  s21_decimal d;

  ck_assert_int_eq(0, s21_from_int_to_decimal(x, &d));
  ck_assert_int_eq(x, d.bits[0]);
}
END_TEST

START_TEST(s21_int_to_dec_test6) {
  int x = 0;
  s21_decimal d;

  ck_assert_int_eq(0, s21_from_int_to_decimal(x, &d));
  ck_assert_int_eq(x, d.bits[0]);
}
END_TEST

START_TEST(s21_int_to_dec_test7) {
  int x = 2147483647;
  s21_decimal d;

  ck_assert_int_eq(0, s21_from_int_to_decimal(x, &d));
  ck_assert_int_eq(x, d.bits[0]);
}
END_TEST

START_TEST(s21_int_to_dec_test8) {
  int x = -2147483647;
  s21_decimal d;

  ck_assert_int_eq(0, s21_from_int_to_decimal(x, &d));
  ck_assert_int_eq(-x, d.bits[0]);
  ck_assert_int_eq(1, s21_get_bit(d, S21_SIGN_BIT));
}
END_TEST

START_TEST(s21_int_to_dec_test9) {
  int x = -2147483648;
  s21_decimal d;

  ck_assert_int_eq(0, s21_from_int_to_decimal(x, &d));
  ck_assert_uint_eq((unsigned int)-x, d.bits[0]);
  ck_assert_int_eq(1, s21_get_bit(d, S21_SIGN_BIT));
}
END_TEST

START_TEST(s21_int_to_dec_test10) {
  int x = -1;
  s21_decimal d;

  ck_assert_int_eq(0, s21_from_int_to_decimal(x, &d));
  ck_assert_uint_eq(-x, d.bits[0]);
  ck_assert_int_eq(1, s21_get_bit(d, S21_SIGN_BIT));
}
END_TEST

Suite* s21_int_to_dec_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_int_to_dec_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_int_to_dec_test1);
  tcase_add_test(tc_core, s21_int_to_dec_test2);
  tcase_add_test(tc_core, s21_int_to_dec_test3);
  tcase_add_test(tc_core, s21_int_to_dec_test4);
  tcase_add_test(tc_core, s21_int_to_dec_test5);
  tcase_add_test(tc_core, s21_int_to_dec_test6);
  tcase_add_test(tc_core, s21_int_to_dec_test7);
  tcase_add_test(tc_core, s21_int_to_dec_test8);
  tcase_add_test(tc_core, s21_int_to_dec_test9);
  tcase_add_test(tc_core, s21_int_to_dec_test10);

  suite_add_tcase(s, tc_core);
  return s;
}