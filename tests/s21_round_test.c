#include "../s21_decimal_tests.h"

START_TEST(test_s21_round_1) {
  s21_decimal dec1;
  dec1.bits[0] = 0xa5;
  dec1.bits[1] = 0x0;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x80010000;
  s21_decimal result;
  result.bits[0] = 0x10;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x80000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_round_2) {
  s21_decimal dec1;
  dec1.bits[0] = 0xf7274;
  dec1.bits[1] = 0x0;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x80030000;
  s21_decimal result;
  result.bits[0] = 0x3f4;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x80000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_round_3) {
  s21_decimal dec1;
  dec1.bits[0] = 0x800003f4;
  dec1.bits[1] = 0x0;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x0;
  s21_decimal result;
  result.bits[0] = 0x800003f4;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x0;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_round_4) {
  s21_decimal dec1;
  dec1.bits[0] = 0x630fffff;
  dec1.bits[1] = 0x6BC75E2D;
  dec1.bits[2] = 0x5;
  dec1.bits[3] = 0x800A0000;
  s21_decimal result;
  result.bits[0] = 0x540BE400;
  result.bits[1] = 0x2;
  result.bits[2] = 0x0;
  result.bits[3] = 0x80000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_round_5) {
  s21_decimal dec1;
  dec1.bits[0] = 0x93F01C52;
  dec1.bits[1] = 0x120;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0xa0000;
  s21_decimal result;
  result.bits[0] = 0x7c;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x0;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_round_6) {
  s21_decimal dec1;
  dec1.bits[0] = 0xCDC77C40;
  dec1.bits[1] = 0x3E250260;
  dec1.bits[2] = 0x204FCE5E;
  dec1.bits[3] = 0x80040000;
  s21_decimal result;
  result.bits[0] = 0xA0FE4E04;
  result.bits[1] = 0x1BCECCED;
  result.bits[2] = 0xD3C2;
  result.bits[3] = 0x80000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_round_7) {
  s21_decimal dec1;
  dec1.bits[0] = 0xA0FE4E04;
  dec1.bits[1] = 0x1BCECCED;
  dec1.bits[2] = 0xD3C2;
  dec1.bits[3] = 0x0;
  s21_decimal res1;
  s21_round(dec1, &res1);
  s21_decimal result;
  result.bits[0] = 0xA0FE4E04;
  result.bits[1] = 0x1BCECCED;
  result.bits[2] = 0xD3C2;
  result.bits[3] = 0x0;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_round_8) {
  s21_decimal src1, origin;
  src1.bits[0] = 2;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 2;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_round_9) {
  s21_decimal src1, origin;
  src1.bits[0] = 0x23;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x10000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x4;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_round_10) {
  s21_decimal src1, origin;
  src1.bits[0] = 0x0;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x0;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_round_11) {
  s21_decimal src1, origin;
  src1.bits[0] = 0x4CD281C5;
  src1.bits[1] = 0x2;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x80000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x4CD281C5;
  origin.bits[1] = 0x2;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_round_12) {
  s21_decimal src1, origin;
  src1.bits[0] = 0xDEB4AA61;
  src1.bits[1] = 0xF4F85EE9;
  src1.bits[2] = 0x2;
  src1.bits[3] = 0x80050000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x8674BB91;
  origin.bits[1] = 0x1F016;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_round_13) {
  s21_decimal src1, origin;
  src1.bits[0] = 0x79B1F98;
  src1.bits[1] = 0x664891A3;
  src1.bits[2] = 0x48B1D;
  src1.bits[3] = 0x80180000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x5;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_round_14) {
  s21_decimal src1, origin;
  src1.bits[0] = 0x4EE43976;
  src1.bits[1] = 0x4B35A1D9;
  src1.bits[2] = 0x19B974BF;
  src1.bits[3] = 0xF0000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0xA41E402E;
  origin.bits[1] = 0x73D;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_round_15) {
  s21_decimal src1, origin;
  src1.bits[0] = 0x788AF4CA;
  src1.bits[1] = 0x620AE487;
  src1.bits[2] = 0x27E41AD5;
  src1.bits[3] = 0x80150000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0xBC614D;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_round_16) {
  s21_decimal src1, origin;
  src1.bits[0] = 0x6D;
  src1.bits[1] = 0xC655B;
  src1.bits[2] = 0x3039;
  src1.bits[3] = 0x1E0000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x0;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(s21_round(src1, &origin), 1);
}
END_TEST

Suite* s21_round_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_round_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_round_1);
  tcase_add_test(tc_core, test_s21_round_2);
  tcase_add_test(tc_core, test_s21_round_3);
  tcase_add_test(tc_core, test_s21_round_4);
  tcase_add_test(tc_core, test_s21_round_5);
  tcase_add_test(tc_core, test_s21_round_6);
  tcase_add_test(tc_core, test_s21_round_7);
  tcase_add_test(tc_core, test_s21_round_8);
  tcase_add_test(tc_core, test_s21_round_9);
  tcase_add_test(tc_core, test_s21_round_10);
  tcase_add_test(tc_core, test_s21_round_11);
  tcase_add_test(tc_core, test_s21_round_12);
  tcase_add_test(tc_core, test_s21_round_13);
  tcase_add_test(tc_core, test_s21_round_14);
  tcase_add_test(tc_core, test_s21_round_15);
  tcase_add_test(tc_core, test_s21_round_16);

  suite_add_tcase(s, tc_core);
  return s;
}
