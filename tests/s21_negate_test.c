#include "../s21_decimal_tests.h"

START_TEST(test_s21_negate_1) {
  // 2
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 2;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);

  s21_decimal s21_result_negate_1;

  ck_assert_int_eq(0, s21_negate(a1, &s21_result_negate_1));
  ck_assert_int_eq(2, s21_result_negate_1.bits[0]);
  ck_assert_int_eq(1, s21_get_bit(s21_result_negate_1, S21_SIGN_BIT));
}
END_TEST

START_TEST(test_s21_negate_2) {
  //-2
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 2;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_decimal s21_result_negate_2;

  ck_assert_int_eq(0, s21_negate(a2, &s21_result_negate_2));
  ck_assert_int_eq(2, s21_result_negate_2.bits[0]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_negate_2, S21_SIGN_BIT));
}
END_TEST

START_TEST(test_s21_negate_3) {
  //+0
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 0;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);

  s21_decimal s21_result_negate_1;

  ck_assert_int_eq(0, s21_negate(a1, &s21_result_negate_1));
  ck_assert_int_eq(0, s21_result_negate_1.bits[0]);
  ck_assert_int_eq(1, s21_get_bit(s21_result_negate_1, S21_SIGN_BIT));
}
END_TEST

START_TEST(test_s21_negate_4) {
  //-0
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 0;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_decimal s21_result_negate_2;

  ck_assert_int_eq(0, s21_negate(a2, &s21_result_negate_2));
  ck_assert_int_eq(0, s21_result_negate_2.bits[0]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_negate_2, S21_SIGN_BIT));
}
END_TEST

START_TEST(test_s21_negate_5) {
  // NULL
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 0;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  ck_assert_int_eq(1, s21_negate(a2, NULL));
}
END_TEST

Suite* s21_negate_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_negate_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_negate_1);
  tcase_add_test(tc_core, test_s21_negate_2);
  tcase_add_test(tc_core, test_s21_negate_3);
  tcase_add_test(tc_core, test_s21_negate_4);
  tcase_add_test(tc_core, test_s21_negate_5);

  suite_add_tcase(s, tc_core);
  return s;
}
