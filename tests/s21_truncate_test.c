#include "../s21_decimal_tests.h"

START_TEST(test_s21_truncate_1) {
  s21_decimal dec1;
  dec1.bits[0] = 0xD3;  // 21.1
  dec1.bits[1] = 0x0;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x10000;
  s21_decimal result;
  result.bits[0] = 0x15;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x0;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_truncate_2) {
  s21_decimal dec1;
  dec1.bits[0] = 0xA5;
  dec1.bits[1] = 0x0;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x10000;
  s21_decimal result;
  result.bits[0] = 0x10;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x0;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_truncate_3) {
  s21_decimal dec1;
  dec1.bits[0] = 0xFFFFFFFF;  // 7922816251426433759354395033.5
  dec1.bits[1] = 0xFFFFFFFF;
  ;
  dec1.bits[2] = 0xFFFFFFFF;
  ;
  dec1.bits[3] = 0x10000;
  s21_decimal result;
  result.bits[0] = 0x99999999;
  result.bits[1] = 0x99999999;
  result.bits[2] = 0x19999999;
  result.bits[3] = 0x0;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_truncate_4) {
  s21_decimal dec1;
  dec1.bits[0] = 0x800000A5;  // 214.7483813
  dec1.bits[1] = 0x0;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x70000;
  float num = 0.0;
  s21_from_decimal_to_float(dec1, &num);
  s21_decimal result;
  result.bits[0] = 0xD6;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x0;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_truncate_5) {
  s21_decimal dec1;
  dec1.bits[3] = 0x000A0000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result;
  result.bits[3] = 0x0;
  result.bits[2] = 0x0;
  result.bits[1] = 0x0;
  result.bits[0] = 0x6DF37F67;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_truncate_6) {
  s21_decimal dec1;
  dec1.bits[3] = 0x800C0000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result;
  result.bits[3] = 0x80000000;
  result.bits[2] = 0x0;
  result.bits[1] = 0x0;
  result.bits[0] = 0x1197998;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_truncate_7) {
  s21_decimal dec1;
  dec1.bits[3] = 0x80000000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result;
  result.bits[3] = 0x80000000;
  result.bits[2] = 0x0;
  result.bits[1] = 0xFFFFFFFF;
  result.bits[0] = 0xFFFFFFFF;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_truncate_8) {
  s21_decimal dec1;
  dec1.bits[0] = 0x6D;
  dec1.bits[1] = 0xC655B;
  dec1.bits[2] = 0x3039;
  dec1.bits[3] = 0xE0000;
  s21_decimal result;
  result.bits[0] = 0x87BC161E;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x0;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_truncate_9) {
  s21_decimal dec1;
  dec1.bits[0] = 0x6D;
  dec1.bits[1] = 0xC655B;
  dec1.bits[2] = 0x3039;
  dec1.bits[3] = 0x1E0000;
  s21_decimal result;
  result.bits[0] = 0x0;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x0;
  ck_assert_int_eq(s21_truncate(dec1, &result), 1);
}
END_TEST

START_TEST(test_s21_truncate_10) {
  s21_decimal dec1;
  dec1.bits[3] = 0x80090000;
  dec1.bits[2] = 0;
  dec1.bits[1] = 0xFFFFEA34;
  dec1.bits[0] = 0xFF837E4F;
  s21_decimal result;
  s21_truncate(dec1, &result);
  s21_decimal res1;

  res1.bits[3] = 0x80000000;
  res1.bits[2] = 0;
  res1.bits[1] = 0x4;
  res1.bits[0] = 0x4B829C70;
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
}
END_TEST

Suite* s21_truncate_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_truncate_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_truncate_1);
  tcase_add_test(tc_core, test_s21_truncate_2);
  tcase_add_test(tc_core, test_s21_truncate_3);
  tcase_add_test(tc_core, test_s21_truncate_3);
  tcase_add_test(tc_core, test_s21_truncate_4);
  tcase_add_test(tc_core, test_s21_truncate_5);
  tcase_add_test(tc_core, test_s21_truncate_6);
  tcase_add_test(tc_core, test_s21_truncate_7);
  tcase_add_test(tc_core, test_s21_truncate_8);
  tcase_add_test(tc_core, test_s21_truncate_9);
  tcase_add_test(tc_core, test_s21_truncate_10);

  suite_add_tcase(s, tc_core);
  return s;
}