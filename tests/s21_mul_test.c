#include "../s21_decimal_tests.h"

START_TEST(test_s21_mul_1) {
  int num1 = -10;
  int num2 = -10;
  int prod_int = 100;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(test_s21_mul_2) {
  int num1 = 10;
  int num2 = 20;
  int prod_int = 200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(test_s21_mul_3) {
  int num1 = -10;
  int num2 = 20;
  int prod_int = -200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(test_s21_mul_4) {
  int num1 = 9403;
  int num2 = 202;
  int res_origin = 1899406;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(test_s21_mul_5) {
  int num1 = -32768;
  int num2 = 2;
  int res_origin = -65536;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(test_s21_mul_6) {
  int num1 = -32768;
  int num2 = 32768;
  int res_origin = -1073741824;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(test_s21_mul_7) {
  float num1 = 94030;
  int num2 = 202;
  float res_origin = 18994060;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(test_s21_mul_8) {
  float num1 = 94030;
  float num2 = 94030;
  float res_origin = 8841640900;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(test_s21_mul_9) {
  s21_decimal dec1 = {{4, 0, 0, 0}};
  s21_decimal dec2 = {{10, 0, 0, 0}};

  s21_decimal d22;
  s21_mul(dec1, dec2, &d22);

  int qqqq = 0;
  s21_from_decimal_to_int(d22, &qqqq);
  ck_assert_int_eq(qqqq, 40);
}
END_TEST

START_TEST(test_s21_mul_10) {
  s21_decimal dec1;
  s21_decimal dec2;
  dec1.bits[0] = 0x131250a3;
  dec1.bits[1] = 0x2cd61c65;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x0;
  dec2.bits[0] = 0x18b473d4;
  dec2.bits[1] = 0x39;
  dec2.bits[2] = 0x0;
  dec2.bits[3] = 0x0;
  s21_decimal res;

  ck_assert_int_eq(s21_mul(dec1, dec2, &res), 1);
}
END_TEST

START_TEST(test_s21_mul_11) {
  s21_decimal dec1;
  s21_decimal dec2;
  dec1.bits[0] = 0x131250a3;
  dec1.bits[1] = 0x2cd61c65;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x0;
  dec2.bits[0] = 0x18b473d4;
  dec2.bits[1] = 0x39;
  dec2.bits[2] = 0x0;
  dec2.bits[3] = 0x80000000;
  s21_decimal res;

  ck_assert_int_eq(s21_mul(dec1, dec2, &res), 2);
}
END_TEST

START_TEST(test_s21_mul_12) {
  s21_decimal dec1;
  s21_decimal dec2;
  dec1.bits[0] = 0x131250a3;
  dec1.bits[1] = 0x2cd61c65;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x0;
  dec2.bits[0] = 0x18b473d4;
  dec2.bits[1] = 0x39;
  dec2.bits[2] = 0x0;
  dec2.bits[3] = 0x30000;
  s21_decimal res;

  ck_assert_int_eq(s21_mul(dec1, dec2, &res), 0);
}
END_TEST

START_TEST(test_s21_mul_13) {
  s21_decimal dec1;
  s21_decimal dec2;
  dec1.bits[0] = 0xb52e2000;
  dec1.bits[1] = 0x425;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x0;
  dec2.bits[0] = 0xed39c000;
  dec2.bits[1] = 0x14ca5c;
  dec2.bits[2] = 0x0;
  dec2.bits[3] = 0x30000;
  s21_decimal res;

  ck_assert_int_eq(s21_mul(dec1, dec2, &res), 0);
}
END_TEST

START_TEST(test_s21_mul_14) {
  s21_decimal dec1;
  s21_decimal dec2;
  dec1.bits[0] = 0xb52e2000;
  dec1.bits[1] = 0x0;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x1c0000;
  dec2.bits[0] = 0xed39c000;
  dec2.bits[1] = 0x14ca5c;
  dec2.bits[2] = 0x0;
  dec2.bits[3] = 0x60000;
  s21_decimal res;

  ck_assert_int_eq(s21_mul(dec1, dec2, &res), 0);
}
END_TEST

START_TEST(test_s21_mul_15) {
  s21_decimal dec1;
  s21_decimal dec2;
  dec1.bits[0] = 0xffffffff;
  dec1.bits[1] = 0xffffffff;
  dec1.bits[2] = 0xffffffff;
  dec1.bits[3] = 0x30000;
  dec2.bits[0] = 0x5;
  dec2.bits[1] = 0x0;
  dec2.bits[2] = 0x0;
  dec2.bits[3] = 0x0;
  s21_decimal res;

  ck_assert_int_eq(s21_mul(dec1, dec2, &res), 0);
}
END_TEST

Suite* s21_mul_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_mul_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_mul_1);
  tcase_add_test(tc_core, test_s21_mul_2);
  tcase_add_test(tc_core, test_s21_mul_3);
  tcase_add_test(tc_core, test_s21_mul_4);
  tcase_add_test(tc_core, test_s21_mul_5);
  tcase_add_test(tc_core, test_s21_mul_6);
  tcase_add_test(tc_core, test_s21_mul_7);
  tcase_add_test(tc_core, test_s21_mul_8);
  tcase_add_test(tc_core, test_s21_mul_9);
  tcase_add_test(tc_core, test_s21_mul_10);
  tcase_add_test(tc_core, test_s21_mul_11);
  tcase_add_test(tc_core, test_s21_mul_12);
  tcase_add_test(tc_core, test_s21_mul_13);
  tcase_add_test(tc_core, test_s21_mul_14);
  tcase_add_test(tc_core, test_s21_mul_15);

  suite_add_tcase(s, tc_core);
  return s;
}