#include "../s21_decimal_tests.h"

START_TEST(test_s21_is_greater_or_equal_1) {
  float num1 = 1.375323;
  float num2 = 1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_2) {
  int num1 = 2;
  int num2 = 1;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_3) {
  float num1 = 1.39;
  float num2 = -1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_4) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_5) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_6) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_7) {
  int num1 = 10;
  int num2 = 3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_8) {
  float num1 = 10423546.34534534;
  float num2 = 3.34534534;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_9) {
  float num1 = -3.34534534;
  float num2 = 3.34534534;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_10) {
  float num1 = 1042634.34534534;
  float num2 = 10424546.34534534;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_11) {
  float num1 = 10426.34534534;
  float num2 = 104234.345345;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_12) {
  float num1 = 1042.5667777;
  float num2 = 1042.345345;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_13) {
  s21_decimal dec5 = {{12345, 0, 0, 0x40000}};  //  1.2345
  s21_decimal dec6 = {{12, 0, 0, 0x80010000}};  //
  ck_assert_int_eq(s21_is_greater_or_equal(dec5, dec6), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dec6, dec5), 0);

  s21_decimal dec7 = {{12345, 0, 0, 0x80040000}};  // -1.2345
  s21_decimal dec8 = {{12, 0, 0, 0x10000}};
  ck_assert_int_eq(s21_is_greater_or_equal(dec7, dec8), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(dec8, dec7), 1);

  s21_decimal dec1 = {{12345, 0, 0, 0x40000}};  //  1.2345
  s21_decimal dec2 = {{12, 0, 0, 0x10000}};
  ck_assert_int_eq(s21_is_greater_or_equal(dec1, dec2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dec2, dec1), 0);

  s21_decimal dec3 = {{12345, 0, 0, 0x80040000}};  // -1.2345
  s21_decimal dec4 = {{12, 0, 0, 0x80010000}};     //

  ck_assert_int_eq(s21_is_greater_or_equal(dec3, dec4), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(dec4, dec3), 1);

  s21_decimal dec9 = {{12345, 0, 0, 0}};
  s21_decimal dec10 = {{12345, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(dec9, dec10), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dec10, dec9), 1);

  s21_decimal dec11 = {{0, 0, 0, 0}};
  s21_decimal dec12 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(dec11, dec12), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dec12, dec11), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_14) {
  //+0
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 0;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  //-0
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 0;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);
  ck_assert_int_eq(1, s21_is_greater_or_equal(a1, a2));
}
END_TEST

Suite* s21_is_greater_or_equal_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_is_greater_or_equal_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_1);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_2);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_3);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_4);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_5);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_6);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_7);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_8);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_9);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_10);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_11);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_12);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_13);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_14);

  suite_add_tcase(s, tc_core);
  return s;
}