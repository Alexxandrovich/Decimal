#include "../s21_decimal_tests.h"

START_TEST(s21_div_test1) {
  int a = 10;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 5;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(a / b, result.bits[0]);
}
END_TEST

START_TEST(s21_div_test2) {
  int a = 123;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 3;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(a / b, result.bits[0]);
}
END_TEST

START_TEST(s21_div_test3) {
  int a = 123000003;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 3;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(a / b, result.bits[0]);
}
END_TEST

START_TEST(s21_div_test4) {
  int a = 213435550;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 5;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(a / b, result.bits[0]);
}
END_TEST

START_TEST(s21_div_test5) {
  int a = 232452;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 1;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(a / b, result.bits[0]);
}
END_TEST

START_TEST(s21_div_test6) {
  int a = 642568;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 31;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(a / b, result.bits[0]);
}
END_TEST

START_TEST(s21_div_test7) {
  long int a = 600000000000;
  s21_decimal d1;
  s21_decimal_init_int(&d1, a);

  int b = 3;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(2431504384, result.bits[0]);
  ck_assert_int_eq(46, result.bits[1]);
}
END_TEST

START_TEST(s21_div_test8) {
  int a = -6425685;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 63;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(1, s21_get_bit(result, S21_SIGN_BIT));
  ck_assert_int_eq(-a / b, result.bits[0]);
}
END_TEST

START_TEST(s21_div_test9) {
  int a = 45246281;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = -659;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(1, s21_get_bit(result, S21_SIGN_BIT));
  ck_assert_int_eq(-a / b, result.bits[0]);
}
END_TEST

START_TEST(s21_div_test10) {
  int a = -98198101;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = -79771;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(0, s21_get_bit(result, S21_SIGN_BIT));
  ck_assert_int_eq(a / b, result.bits[0]);
}
END_TEST

START_TEST(s21_div_test11) {
  int a = 123;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 0;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(S21_STATUS_ERROR_DIV_BY_ZERO, s21_div(d1, d2, &result));
}
END_TEST

START_TEST(s21_div_test12) {
  int a = 1;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 3;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(89478485, result.bits[0]);
  ck_assert_int_eq(347537611, result.bits[1]);
  ck_assert_int_eq(180700362, result.bits[2]);
  ck_assert_int_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test13) {
  int a = 1;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 6;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq((unsigned int)2192222891, result.bits[0]);
  ck_assert_int_eq(173768805, result.bits[1]);
  ck_assert_int_eq(90350181, result.bits[2]);
  ck_assert_int_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test14) {
  int a = 3;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 132;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(494165271, result.bits[0]);
  ck_assert_int_eq(999824677, result.bits[1]);
  ck_assert_int_eq(12320479, result.bits[2]);
  ck_assert_int_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test15) {
  int a = 110;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 113;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq((unsigned int)2845890941, result.bits[0]);
  ck_assert_int_eq(26710282, result.bits[1]);
  ck_assert_int_eq(527709022, result.bits[2]);
  ck_assert_int_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test16) {
  int a = 2;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 3;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(178956971, result.bits[0]);
  ck_assert_int_eq(695075222, result.bits[1]);
  ck_assert_int_eq(361400724, result.bits[2]);
  ck_assert_int_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test17) {
  int a = 5;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 8;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(625, result.bits[0]);
  ck_assert_int_eq(0, result.bits[1]);
  ck_assert_int_eq(0, result.bits[2]);
  ck_assert_int_eq(196608, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test18) {
  int a = 7;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 12;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(1230329173, result.bits[0]);
  ck_assert_uint_eq((unsigned int)2755674467, result.bits[1]);
  ck_assert_int_eq(316225633, result.bits[2]);
  ck_assert_int_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test19) {
  int a = 753463;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 636354354;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(457754317, result.bits[0]);
  ck_assert_int_eq(1077651566, result.bits[1]);
  ck_assert_int_eq(641864, result.bits[2]);
  ck_assert_int_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test20) {
  int a = 1;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  long int b = 536870912L * 64L;
  s21_decimal d2;
  s21_decimal_init_int(&d2, b);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq((unsigned int)3351552076, result.bits[0]);
  ck_assert_int_eq(67762635, result.bits[1]);
  ck_assert_int_eq(0, result.bits[2]);
  ck_assert_int_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test21) {
  int a = 1;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 536870912;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq((unsigned int)4045935368, result.bits[0]);
  ck_assert_int_eq(41841393, result.bits[1]);
  ck_assert_int_eq(1, result.bits[2]);
  ck_assert_int_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test22) {
  int a = 12345235;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 123;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(1363387500, result.bits[0]);
  ck_assert_int_eq(496555194, result.bits[1]);
  ck_assert_int_eq(544094740, result.bits[2]);
  ck_assert_int_eq(1507328, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test23) {
  int a = 4444;
  s21_decimal d1;
  s21_from_int_to_decimal(a, &d1);

  int b = 11;
  s21_decimal d2;
  s21_from_int_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(404, result.bits[0]);
  ck_assert_int_eq(0, result.bits[1]);
  ck_assert_int_eq(0, result.bits[2]);
  ck_assert_int_eq(0, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test24) {
  long int a = 853489572398;
  s21_decimal d1;
  s21_decimal_init_int(&d1, a);

  long int b = 467238568921;
  s21_decimal d2;
  s21_decimal_init_int(&d2, b);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(4060629545, result.bits[0]);
  ck_assert_uint_eq(4211819496, result.bits[1]);
  ck_assert_int_eq(990238509, result.bits[2]);
  ck_assert_int_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test25) {
  long int a = -88567328;
  s21_decimal d1;
  s21_decimal_init_int(&d1, a);

  long int b = 21;
  s21_decimal d2;
  s21_decimal_init_int(&d2, b);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(2000483279, result.bits[0]);
  ck_assert_int_eq(699082260, result.bits[1]);
  ck_assert_uint_eq(2286306891, result.bits[2]);
  ck_assert_int_eq(2148925440, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test26) {
  float a = 18.62;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 3;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(1923787435, result.bits[0]);
  ck_assert_uint_eq(4065968631, result.bits[1]);
  ck_assert_uint_eq(3364640741, result.bits[2]);
  ck_assert_int_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test27) {
  float a = 186.2;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 3;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_int_eq(1923787435, result.bits[0]);
  ck_assert_uint_eq(4065968631, result.bits[1]);
  ck_assert_uint_eq(3364640741, result.bits[2]);
  ck_assert_int_eq(1769472, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test28) {
  float a = 312.1234;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = -7;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(3655036343, result.bits[0]);
  ck_assert_uint_eq(722845899, result.bits[1]);
  ck_assert_uint_eq(2417177631, result.bits[2]);
  ck_assert_uint_eq(2149253120, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test29) {
  float a = 1;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 1e-3;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(1000, result.bits[0]);
  ck_assert_uint_eq(0, result.bits[1]);
  ck_assert_uint_eq(0, result.bits[2]);
  ck_assert_uint_eq(0, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test30) {
  float a = 142735;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 1.00011;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(630214443, result.bits[0]);
  ck_assert_uint_eq(1424880671, result.bits[1]);
  ck_assert_uint_eq(773682880, result.bits[2]);
  ck_assert_uint_eq(1507328, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test31) {
  float a = 1e28;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 0.1;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(S21_STATUS_ERROR_LARGE, s21_div(d1, d2, &result));
}
END_TEST

START_TEST(s21_div_test32) {
  float a = 0.1;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 1e28;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(S21_STATUS_ERROR_SMALL, s21_div(d1, d2, &result));
}
END_TEST

START_TEST(s21_div_test33) {
  float a = 0.1;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 3;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(1297438037, result.bits[0]);
  ck_assert_uint_eq(893747220, result.bits[1]);
  ck_assert_uint_eq(18070036, result.bits[2]);
  ck_assert_uint_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test34) {
  float a = 0.05;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 31;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(2418083906, result.bits[0]);
  ck_assert_uint_eq(2537097811, result.bits[1]);
  ck_assert_uint_eq(874356, result.bits[2]);
  ck_assert_uint_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test35) {
  float a = 0.115;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 19;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(732899436, result.bits[0]);
  ck_assert_uint_eq(659597682, result.bits[1]);
  ck_assert_uint_eq(3281138, result.bits[2]);
  ck_assert_uint_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test36) {
  float a = 1;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 0.3;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(894784853, result.bits[0]);
  ck_assert_uint_eq(3475376110, result.bits[1]);
  ck_assert_uint_eq(1807003620, result.bits[2]);
  ck_assert_uint_eq(1835008, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test37) {
  float a = 1;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 0.003;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(894784853, result.bits[0]);
  ck_assert_uint_eq(3475376110, result.bits[1]);
  ck_assert_uint_eq(1807003620, result.bits[2]);
  ck_assert_uint_eq(1703936, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test38) {
  float a = 3;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 5;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(6, result.bits[0]);
  ck_assert_uint_eq(0, result.bits[1]);
  ck_assert_uint_eq(0, result.bits[2]);
  ck_assert_uint_eq(65536, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test39) {
  float a = 3;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 3;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(1, result.bits[0]);
  ck_assert_uint_eq(0, result.bits[1]);
  ck_assert_uint_eq(0, result.bits[2]);
  ck_assert_uint_eq(0, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test40) {
  float a = -1;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = -1;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(1, result.bits[0]);
  ck_assert_uint_eq(0, result.bits[1]);
  ck_assert_uint_eq(0, result.bits[2]);
  ck_assert_uint_eq(0, result.bits[3]);
}
END_TEST

START_TEST(s21_div_test41) {
  float a = 0;
  s21_decimal d1;
  s21_from_float_to_decimal(a, &d1);

  float b = 1343;
  s21_decimal d2;
  s21_from_float_to_decimal(b, &d2);

  s21_decimal result;
  ck_assert_int_eq(0, s21_div(d1, d2, &result));
  ck_assert_uint_eq(0, result.bits[0]);
  ck_assert_uint_eq(0, result.bits[1]);
  ck_assert_uint_eq(0, result.bits[2]);
  ck_assert_uint_eq(0, result.bits[3]);
}
END_TEST

Suite* s21_div_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_div_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_div_test1);
  tcase_add_test(tc_core, s21_div_test2);
  tcase_add_test(tc_core, s21_div_test3);
  tcase_add_test(tc_core, s21_div_test4);
  tcase_add_test(tc_core, s21_div_test5);
  tcase_add_test(tc_core, s21_div_test6);
  tcase_add_test(tc_core, s21_div_test7);
  tcase_add_test(tc_core, s21_div_test8);
  tcase_add_test(tc_core, s21_div_test9);
  tcase_add_test(tc_core, s21_div_test10);
  tcase_add_test(tc_core, s21_div_test11);
  tcase_add_test(tc_core, s21_div_test12);
  tcase_add_test(tc_core, s21_div_test13);
  tcase_add_test(tc_core, s21_div_test14);
  tcase_add_test(tc_core, s21_div_test15);
  tcase_add_test(tc_core, s21_div_test16);
  tcase_add_test(tc_core, s21_div_test17);
  tcase_add_test(tc_core, s21_div_test18);
  tcase_add_test(tc_core, s21_div_test19);
  tcase_add_test(tc_core, s21_div_test20);
  tcase_add_test(tc_core, s21_div_test21);
  tcase_add_test(tc_core, s21_div_test22);
  tcase_add_test(tc_core, s21_div_test23);
  tcase_add_test(tc_core, s21_div_test24);
  tcase_add_test(tc_core, s21_div_test25);
  tcase_add_test(tc_core, s21_div_test26);
  tcase_add_test(tc_core, s21_div_test27);
  tcase_add_test(tc_core, s21_div_test28);
  tcase_add_test(tc_core, s21_div_test29);
  tcase_add_test(tc_core, s21_div_test30);
  tcase_add_test(tc_core, s21_div_test31);
  tcase_add_test(tc_core, s21_div_test32);
  tcase_add_test(tc_core, s21_div_test33);
  tcase_add_test(tc_core, s21_div_test34);
  tcase_add_test(tc_core, s21_div_test35);
  tcase_add_test(tc_core, s21_div_test36);
  tcase_add_test(tc_core, s21_div_test37);
  tcase_add_test(tc_core, s21_div_test38);
  tcase_add_test(tc_core, s21_div_test39);
  tcase_add_test(tc_core, s21_div_test40);
  tcase_add_test(tc_core, s21_div_test41);
  suite_add_tcase(s, tc_core);
  return s;
}