#include "../s21_decimal_tests.h"

START_TEST(test_s21_floor_1) {
  // 5.123
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 5123;
  s21_set_degree(&a1, 3);
  s21_set_bit(&a1, 0, S21_SIGN_BIT);

  s21_decimal s21_result_1;

  ck_assert_int_eq(0, s21_floor(a1, &s21_result_1));
  ck_assert_int_eq(5, s21_result_1.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(s21_result_1));
}
END_TEST

START_TEST(test_s21_floor_2) {
  // 100.1
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 1001;
  s21_set_degree(&a2, 1);
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  s21_decimal s21_result_2;

  ck_assert_int_eq(0, s21_floor(a2, &s21_result_2));
  ck_assert_int_eq(100, s21_result_2.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(s21_result_2));
}
END_TEST

START_TEST(test_s21_floor_3) {
  // 0.1
  s21_decimal a3;
  s21_decimal_init(&a3);
  a3.bits[0] = 1;
  s21_set_degree(&a3, 1);
  s21_set_bit(&a3, 0, S21_SIGN_BIT);

  s21_decimal s21_result_3;

  ck_assert_int_eq(0, s21_floor(a3, &s21_result_3));
  ck_assert_int_eq(0, s21_result_3.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(s21_result_3));
}
END_TEST

START_TEST(test_s21_floor_4) {
  //-1.5
  s21_decimal a4;
  s21_decimal_init(&a4);
  a4.bits[0] = 15;
  s21_set_degree(&a4, 1);
  s21_set_bit(&a4, 1, S21_SIGN_BIT);

  s21_decimal s21_result_4;

  ck_assert_int_eq(0, s21_floor(a4, &s21_result_4));
  ck_assert_int_eq(2, s21_result_4.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(s21_result_4));
  ck_assert_int_eq(1, s21_get_bit(s21_result_4, S21_SIGN_BIT));
}
END_TEST

START_TEST(test_s21_floor_5) {
  //-999.999
  s21_decimal a5;
  s21_decimal_init(&a5);
  a5.bits[0] = 999999;
  s21_set_degree(&a5, 3);
  s21_set_bit(&a5, 1, S21_SIGN_BIT);

  s21_decimal s21_result_5;

  ck_assert_int_eq(0, s21_floor(a5, &s21_result_5));
  ck_assert_int_eq(1000, s21_result_5.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(s21_result_5));
  ck_assert_int_eq(1, s21_get_bit(s21_result_5, S21_SIGN_BIT));
}
END_TEST

START_TEST(test_s21_floor_6) {
  // 123
  s21_decimal a6;
  s21_decimal_init(&a6);
  a6.bits[0] = 123;
  s21_set_degree(&a6, 0);
  s21_set_bit(&a6, 0, S21_SIGN_BIT);

  s21_decimal s21_result_6;

  ck_assert_int_eq(0, s21_floor(a6, &s21_result_6));
  ck_assert_int_eq(123, s21_result_6.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(s21_result_6));
  ck_assert_int_eq(0, s21_get_bit(s21_result_6, S21_SIGN_BIT));
}
END_TEST

START_TEST(test_s21_floor_7) {
  //-123
  s21_decimal a7;
  s21_decimal_init(&a7);
  a7.bits[0] = 123;
  s21_set_degree(&a7, 0);
  s21_set_bit(&a7, 1, S21_SIGN_BIT);

  s21_decimal s21_result_7;

  ck_assert_int_eq(0, s21_floor(a7, &s21_result_7));
  ck_assert_int_eq(123, s21_result_7.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(s21_result_7));
  ck_assert_int_eq(1, s21_get_bit(s21_result_7, S21_SIGN_BIT));
}
END_TEST

START_TEST(test_s21_floor_8) {
  // NULL
  //-123
  s21_decimal a7;
  s21_decimal_init(&a7);
  a7.bits[0] = 123;
  s21_set_degree(&a7, 0);
  s21_set_bit(&a7, 1, S21_SIGN_BIT);

  ck_assert_int_eq(1, s21_floor(a7, NULL));
}
END_TEST

START_TEST(test_s21_floor_9) {
  s21_decimal result, value[4] = {{{0}},
                                  {{42, 0, 0, 0}},
                                  {{2199, 0, 0, 131072}},
                                  {{2142, 0, 0, -2147352576}}};
  unsigned int answer[4][4] = {
      {0}, {42, 0, 0, 0}, {21, 0, 0, 0}, {22, 0, 0, -2147483648}};
  for (int i = 0; i < 4; i++) {
    s21_floor(value[i], &result);
    for (int j = 0; j < 4; j++) {
      ck_assert(result.bits[j] == answer[i][j]);
    };
  };
}
END_TEST

START_TEST(test_s21_floor_10) {
  // 6678,9
  s21_decimal a3;
  s21_decimal_init(&a3);
  a3.bits[0] = 66789;
  s21_set_degree(&a3, 1);
  s21_set_bit(&a3, 0, S21_SIGN_BIT);

  s21_decimal s21_result_3;

  ck_assert_int_eq(0, s21_floor(a3, &s21_result_3));
  ck_assert_int_eq(6678, s21_result_3.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(s21_result_3));
}
END_TEST

START_TEST(test_s21_floor_11) {
  // 6.9999999
  s21_decimal a3;
  s21_decimal_init(&a3);
  a3.bits[0] = 69999999;
  s21_set_degree(&a3, 7);
  s21_set_bit(&a3, 0, S21_SIGN_BIT);

  s21_decimal s21_result_3;

  ck_assert_int_eq(0, s21_floor(a3, &s21_result_3));
  ck_assert_int_eq(6, s21_result_3.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(s21_result_3));
}
END_TEST

Suite* s21_floor_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_floor_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_floor_1);
  tcase_add_test(tc_core, test_s21_floor_2);
  tcase_add_test(tc_core, test_s21_floor_3);
  tcase_add_test(tc_core, test_s21_floor_4);
  tcase_add_test(tc_core, test_s21_floor_5);
  tcase_add_test(tc_core, test_s21_floor_6);
  tcase_add_test(tc_core, test_s21_floor_7);
  tcase_add_test(tc_core, test_s21_floor_8);
  tcase_add_test(tc_core, test_s21_floor_9);
  tcase_add_test(tc_core, test_s21_floor_10);
  tcase_add_test(tc_core, test_s21_floor_11);

  suite_add_tcase(s, tc_core);
  return s;
}
