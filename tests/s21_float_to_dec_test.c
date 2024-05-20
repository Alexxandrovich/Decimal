#include "../s21_decimal_tests.h"

START_TEST(s21_float_to_dec_test1) {
  float x = 123.456f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(123456, d.bits[0]);
  ck_assert_int_eq(3, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test2) {
  float x = 1.996646f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(1996646, d.bits[0]);
  ck_assert_int_eq(6, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test3) {
  float x = 0.9999999f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(9999999, d.bits[0]);
  ck_assert_int_eq(7, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test4) {
  float x = 8634.8f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(86348, d.bits[0]);
  ck_assert_int_eq(1, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test5) {
  float x = 999999.0f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(999999, d.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test6) {
  float x = 1.000005f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(1000005, d.bits[0]);
  ck_assert_int_eq(6, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test7) {
  float x = 1.9999899f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(199999, d.bits[0]);
  ck_assert_int_eq(5, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test8) {
  float x = 23567.1234f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(2356712, d.bits[0]);
  ck_assert_int_eq(2, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test9) {
  float x = 5555555.5f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(5555556, d.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test10) {
  float x = 9999.88999f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(999989, d.bits[0]);
  ck_assert_int_eq(2, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test11) {
  float x = 66.6602f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(666602, d.bits[0]);
  ck_assert_int_eq(4, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test12) {
  float x = 100.001f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(100001, d.bits[0]);
  ck_assert_int_eq(3, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test13) {
  float x = 9874.3367f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(9874337, d.bits[0]);
  ck_assert_int_eq(3, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test14) {
  float x = 0.556677002f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(556677, d.bits[0]);
  ck_assert_int_eq(6, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test15) {
  float x = 0.0000001f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(1, d.bits[0]);
  ck_assert_int_eq(7, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test16) {
  float x = 0.000000123f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(123, d.bits[0]);
  ck_assert_int_eq(9, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test17) {
  float x = 0.0000000000009999999f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(9999999, d.bits[0]);
  ck_assert_int_eq(19, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test18) {
  float x = 0.000000000000000000000000001f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(1, d.bits[0]);
  ck_assert_int_eq(27, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test19) {
  float x = 0.0000000888995585888f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(8889956, d.bits[0]);
  ck_assert_int_eq(14, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test20) {
  float x = 0.0000000696877000288f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(696877, d.bits[0]);
  ck_assert_int_eq(13, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test21) {
  float x = 123456789.0f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(123456800, d.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test22) {
  float x = 199999999.0f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(200000000, d.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test23) {
  float x = 199999999.0f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(200000000, d.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test24) {
  float x = 9999999.9999f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(10000000, d.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test25) {
  float x = 9999999.2f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(9999999, d.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test26) {
  float x = 2990004325543543534352.0f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(2769420288, d.bits[0]);
  ck_assert_int_eq(379853895, d.bits[1]);
  ck_assert_int_eq(162, d.bits[2]);
  ck_assert_int_eq(0, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test27) {
  float x = S21_MIN_DECIMAL;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(1, d.bits[0]);
  ck_assert_int_eq(0, d.bits[1]);
  ck_assert_int_eq(0, d.bits[2]);
  ck_assert_int_eq(28, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test28) {
  float x = 0.0f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(0, d.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test29) {
  float x = 1e-29f;
  s21_decimal d;
  ck_assert_int_eq(1, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(0, d.bits[0]);
  ck_assert_int_eq(0, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test30) {
  float x = 8e28;
  s21_decimal d;
  ck_assert_int_eq(1, s21_from_float_to_decimal(x, &d));
}
END_TEST

START_TEST(s21_float_to_dec_test31) {
  float x = INFINITY;
  s21_decimal d;
  ck_assert_int_eq(1, s21_from_float_to_decimal(x, &d));
}
END_TEST

START_TEST(s21_float_to_dec_test32) {
  float x = -INFINITY;
  s21_decimal d;
  ck_assert_int_eq(1, s21_from_float_to_decimal(x, &d));
}
END_TEST

START_TEST(s21_float_to_dec_test33) {
  float x = -9999999.2f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(9999999, d.bits[0]);
  ck_assert_int_eq(1, s21_get_bit(d, 127));
  ck_assert_int_eq(0, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test34) {
  float x = -1.996646f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(1996646, d.bits[0]);
  ck_assert_int_eq(1, s21_get_bit(d, 127));
  ck_assert_int_eq(6, s21_get_degree(d));
}
END_TEST

START_TEST(s21_float_to_dec_test35) {
  float x = -1921.6778f;
  s21_decimal d;
  ck_assert_int_eq(0, s21_from_float_to_decimal(x, &d));
  ck_assert_int_eq(1921678, d.bits[0]);
  ck_assert_int_eq(1, s21_get_bit(d, 127));
  ck_assert_int_eq(3, s21_get_degree(d));
}
END_TEST

Suite* s21_float_to_dec_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_float_to_dec_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_float_to_dec_test1);
  tcase_add_test(tc_core, s21_float_to_dec_test2);
  tcase_add_test(tc_core, s21_float_to_dec_test3);
  tcase_add_test(tc_core, s21_float_to_dec_test4);
  tcase_add_test(tc_core, s21_float_to_dec_test5);
  tcase_add_test(tc_core, s21_float_to_dec_test6);
  tcase_add_test(tc_core, s21_float_to_dec_test7);
  tcase_add_test(tc_core, s21_float_to_dec_test8);
  tcase_add_test(tc_core, s21_float_to_dec_test9);
  tcase_add_test(tc_core, s21_float_to_dec_test10);
  tcase_add_test(tc_core, s21_float_to_dec_test11);
  tcase_add_test(tc_core, s21_float_to_dec_test12);
  tcase_add_test(tc_core, s21_float_to_dec_test13);
  tcase_add_test(tc_core, s21_float_to_dec_test14);
  tcase_add_test(tc_core, s21_float_to_dec_test15);
  tcase_add_test(tc_core, s21_float_to_dec_test16);
  tcase_add_test(tc_core, s21_float_to_dec_test17);
  tcase_add_test(tc_core, s21_float_to_dec_test18);
  tcase_add_test(tc_core, s21_float_to_dec_test19);
  tcase_add_test(tc_core, s21_float_to_dec_test20);
  tcase_add_test(tc_core, s21_float_to_dec_test21);
  tcase_add_test(tc_core, s21_float_to_dec_test22);
  tcase_add_test(tc_core, s21_float_to_dec_test23);
  tcase_add_test(tc_core, s21_float_to_dec_test24);
  tcase_add_test(tc_core, s21_float_to_dec_test25);
  tcase_add_test(tc_core, s21_float_to_dec_test26);
  tcase_add_test(tc_core, s21_float_to_dec_test27);
  tcase_add_test(tc_core, s21_float_to_dec_test28);
  tcase_add_test(tc_core, s21_float_to_dec_test29);
  tcase_add_test(tc_core, s21_float_to_dec_test30);
  tcase_add_test(tc_core, s21_float_to_dec_test31);
  tcase_add_test(tc_core, s21_float_to_dec_test32);
  tcase_add_test(tc_core, s21_float_to_dec_test33);
  tcase_add_test(tc_core, s21_float_to_dec_test34);
  tcase_add_test(tc_core, s21_float_to_dec_test35);

  suite_add_tcase(s, tc_core);
  return s;
}