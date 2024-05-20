#include "../s21_decimal_tests.h"

START_TEST(test_s21_add_1) {
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

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(4, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(0, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_2) {
  // 100
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 100;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  // 10
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 10;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(110, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(0, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_3) {
  // 10
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 10;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  // 100
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 100;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(110, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(0, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_4) {
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

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(0, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(0, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_5) {
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

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(0, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(0, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_6) {
  //-0
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 0;
  s21_set_bit(&a1, 1, S21_SIGN_BIT);
  //+0
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 0;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(0, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(0, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_7) {
  // 2
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 2;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  //-2
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 2;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(0, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(0, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_8) {
  // 100
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 100;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  //-10
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 10;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(90, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(0, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_9) {
  // 10
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 10;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);
  //-100
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 100;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(90, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(1, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(0, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_10) {
  //-2
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 2;
  s21_set_bit(&a1, 1, S21_SIGN_BIT);
  //-2
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 2;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(4, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(1, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(0, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_11) {
  //-100
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 100;
  s21_set_bit(&a1, 1, S21_SIGN_BIT);
  //-10
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 10;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(110, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(1, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(0, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_12) {
  // 2.123
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 2123;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);

  //-2.123
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 2123;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_set_degree(&a1, 3);
  s21_set_degree(&a2, 3);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(0, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(0, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_13) {
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

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(224645, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(5, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_14) {
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

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(224645, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(5, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_15) {
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

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(45, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(1, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(5, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_16) {
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

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(45, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(5, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_17) {
  // 100 : 10^29
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 100;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);

  // 10 : 10^28
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 10;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  s21_set_degree(&a1, 29);
  s21_set_degree(&a2, 28);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(2, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(27, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_18) {
  // 100 : 10^28
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 100;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);

  // 1000 : 10^30
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 1000;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  s21_set_degree(&a1, 28);
  s21_set_degree(&a2, 30);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(11, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(27, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_19) {
  // MAX
  s21_decimal a1;
  s21_decimal_init(&a1);
  s21_set_bit(&a1, 1, 95);
  s21_set_bit(&a1, 0, S21_SIGN_BIT);

  // MAX
  s21_decimal a2;
  s21_decimal_init(&a2);
  s21_set_bit(&a2, 1, 95);
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  s21_set_degree(&a1, 0);
  s21_set_degree(&a2, 0);

  s21_decimal s21_result_add;

  ck_assert_int_eq(1, s21_add(a1, a2, &s21_result_add));
}
END_TEST

START_TEST(test_s21_add_20) {
  //-MAX
  s21_decimal a1;
  s21_decimal_init(&a1);
  s21_set_bit(&a1, 1, 95);
  s21_set_bit(&a1, 1, S21_SIGN_BIT);

  //-MAX
  s21_decimal a2;
  s21_decimal_init(&a2);
  s21_set_bit(&a2, 1, 95);
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_set_degree(&a1, 0);
  s21_set_degree(&a2, 0);

  s21_decimal s21_result_add;

  ck_assert_int_eq(2, s21_add(a1, a2, &s21_result_add));
}
END_TEST

START_TEST(test_s21_add_21) {
  s21_decimal result,
      val1[7] = {{{0}},
                 {{21, 0, 0, -2147483648}},
                 {{42, 0, 0, 0}},
                 {{390078125, 0, 0, -2147024896}},
                 {{76540625, 0, 0, 262144}},
                 {{-1, -1, -1, 0}},
                 {{-1, -1, -1, -2147483648}}},
      val2[7] = {{{0}},
                 {{21, 0, 0, -2147483648}},
                 {{21, 0, 0, -2147483648}},
                 {{1261658125, 0, 0, 458752}},
                 {{1261658175, 0, 0, 458752}},
                 {{21, 0, 0, 0}},
                 {{21, 0, 0, -2147483648}}};
  unsigned int answers[5][4] = {{0},
                                {42, 0, 0, -2147483648},
                                {21, 0, 0, 0},
                                {87158, 0, 0, 196608},
                                {492871847, 18, 0, 458752}};
  for (int i = 0; i < 5; i++) {
    s21_add(val1[i], val2[i], &result);
    for (int j = 0; j < 4; j++) {
      ck_assert(result.bits[j] == answers[i][j]);
    };
  };
  ck_assert(s21_add(val1[5], val2[5], &result) == 1);
  ck_assert(s21_add(val1[6], val2[6], &result) == 2);
}
END_TEST

START_TEST(test_s21_add_22) {
  // 1.12345
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 112345;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);

  //-1.00045
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 100045;
  s21_set_bit(&a2, 1, S21_SIGN_BIT);

  s21_set_degree(&a1, 5);
  s21_set_degree(&a2, 5);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(123, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(3, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_23) {
  // 111 : 10^28
  s21_decimal a1;
  s21_decimal_init(&a1);
  a1.bits[0] = 111;
  s21_set_bit(&a1, 0, S21_SIGN_BIT);

  // 1000 : 10^30
  s21_decimal a2;
  s21_decimal_init(&a2);
  a2.bits[0] = 1000;
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  s21_set_degree(&a1, 28);
  s21_set_degree(&a2, 30);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
  ck_assert_int_eq(121, s21_result_add.bits[0]);
  ck_assert_int_eq(0, s21_result_add.bits[1]);
  ck_assert_int_eq(0, s21_result_add.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(s21_result_add, S21_SIGN_BIT));
  ck_assert_int_eq(28, s21_get_degree(s21_result_add));
}
END_TEST

START_TEST(test_s21_add_24) {
  // overflow test
  s21_decimal a1;
  s21_decimal_init(&a1);
  s21_set_bit(&a1, 1, 95);
  s21_set_bit(&a1, 0, S21_SIGN_BIT);

  // overflow test
  s21_decimal a2;
  s21_decimal_init(&a2);
  s21_set_bit(&a2, 1, 95);
  s21_set_bit(&a2, 0, S21_SIGN_BIT);

  s21_set_degree(&a1, 1);
  s21_set_degree(&a2, 1);

  s21_decimal s21_result_add;

  ck_assert_int_eq(0, s21_add(a1, a2, &s21_result_add));
}
END_TEST

Suite* s21_add_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_add_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_add_1);
  tcase_add_test(tc_core, test_s21_add_2);
  tcase_add_test(tc_core, test_s21_add_3);
  tcase_add_test(tc_core, test_s21_add_4);
  tcase_add_test(tc_core, test_s21_add_5);
  tcase_add_test(tc_core, test_s21_add_6);
  tcase_add_test(tc_core, test_s21_add_7);
  tcase_add_test(tc_core, test_s21_add_8);
  tcase_add_test(tc_core, test_s21_add_9);
  tcase_add_test(tc_core, test_s21_add_10);
  tcase_add_test(tc_core, test_s21_add_11);
  tcase_add_test(tc_core, test_s21_add_12);
  tcase_add_test(tc_core, test_s21_add_13);
  tcase_add_test(tc_core, test_s21_add_14);
  tcase_add_test(tc_core, test_s21_add_15);
  tcase_add_test(tc_core, test_s21_add_16);
  tcase_add_test(tc_core, test_s21_add_17);
  tcase_add_test(tc_core, test_s21_add_18);
  tcase_add_test(tc_core, test_s21_add_19);
  tcase_add_test(tc_core, test_s21_add_20);
  tcase_add_test(tc_core, test_s21_add_21);
  tcase_add_test(tc_core, test_s21_add_22);
  tcase_add_test(tc_core, test_s21_add_23);
  tcase_add_test(tc_core, test_s21_add_24);
  suite_add_tcase(s, tc_core);
  return s;
}