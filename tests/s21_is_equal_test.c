#include "../s21_decimal_tests.h"

START_TEST(test_s21_is_equal_1) {
  // 2
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 2;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  // 2
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 2;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  ck_assert_int_eq(1, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_2) {
  // 2
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 2;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  // 3
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 3;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  ck_assert_int_eq(0, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_3) {
  // 3
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 3;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  // 2
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 2;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  ck_assert_int_eq(0, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_4) {
  //+0
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 0;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  //+0
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 0;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  ck_assert_int_eq(1, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_5) {
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

  ck_assert_int_eq(1, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_6) {
  //+1
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 1;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  //-1
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 1;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  ck_assert_int_eq(0, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_7) {
  //-1
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 1;
  s21_set_bit(&a1, 1, S21_SIGN_BIT);
  //+1
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 1;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  ck_assert_int_eq(0, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_8) {
  // 1.12345
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 112345;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  // 1.123
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 1123;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  s21_set_degree(&a1, 5);
  s21_set_degree(&a2, 3);

  ck_assert_int_eq(0, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_9) {
  // 1.123
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 1123;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  // 1.12345
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 112345;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  s21_set_degree(&a1, 3);
  s21_set_degree(&a2, 5);

  ck_assert_int_eq(0, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_10) {
  // 1.12345
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 112345;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  //-1.123
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 1123;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_set_degree(&a1, 5);
  s21_set_degree(&a2, 3);

  ck_assert_int_eq(0, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_11) {
  // 1.123
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 1123;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  //-1.12345
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 112345;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_set_degree(&a1, 3);
  s21_set_degree(&a2, 5);

  ck_assert_int_eq(0, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_12) {
  // 1.123
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 1123;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  // 1.123
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 1123;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  s21_set_degree(&a1, 3);
  s21_set_degree(&a2, 3);

  ck_assert_int_eq(1, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_13) {
  //-1.123
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 1123;
  s21_set_bit(&a1, 1, S21_SIGN_BIT);
  //-1.123
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 1123;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_set_degree(&a1, 3);
  s21_set_degree(&a2, 3);

  ck_assert_int_eq(1, s21_is_equal(a1, a2));
}
END_TEST

START_TEST(test_s21_is_equal_14) {
  s21_decimal val1[5] = {{{0}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, -2147483648}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, -2147483648}}},
              val2[5] = {{{0}},
                         {{21, 0, 1, 0}},
                         {{42, 0, 0, -2147483648}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, 196608}}};
  int answers[5] = {1, 0, 1, 1, 0};
  for (int i = 0; i < 5; i++) {
    ck_assert(s21_is_equal(val1[i], val2[i]) == answers[i]);
  };
}
END_TEST

Suite* s21_is_equal_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_is_equal_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_is_equal_1);
  tcase_add_test(tc_core, test_s21_is_equal_2);
  tcase_add_test(tc_core, test_s21_is_equal_3);
  tcase_add_test(tc_core, test_s21_is_equal_4);
  tcase_add_test(tc_core, test_s21_is_equal_5);
  tcase_add_test(tc_core, test_s21_is_equal_6);
  tcase_add_test(tc_core, test_s21_is_equal_7);
  tcase_add_test(tc_core, test_s21_is_equal_8);
  tcase_add_test(tc_core, test_s21_is_equal_9);
  tcase_add_test(tc_core, test_s21_is_equal_10);
  tcase_add_test(tc_core, test_s21_is_equal_11);
  tcase_add_test(tc_core, test_s21_is_equal_12);
  tcase_add_test(tc_core, test_s21_is_equal_13);
  tcase_add_test(tc_core, test_s21_is_equal_14);

  suite_add_tcase(s, tc_core);
  return s;
}