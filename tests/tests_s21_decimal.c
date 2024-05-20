#include "../s21_decimal_tests.h"

int main(void) {
  printf("\n\n \033[97m\033[106m|| FUNCTIONS||\033[0m \n\n");
  Suite* suite_18_func[] = {s21_add_test(),
                            s21_sub_test(),
                            s21_mul_test(),
                            s21_div_test(),
                            s21_is_less_test(),
                            s21_is_less_or_equal_test(),
                            s21_is_greater_test(),
                            s21_is_greater_or_equal_test(),
                            s21_is_equal_test(),
                            s21_not_equal_test(),
                            s21_int_to_dec_test(),
                            s21_float_to_dec_test(),
                            s21_dec_to_int_test(),
                            s21_dec_to_float_test(),
                            s21_floor_test(),
                            s21_round_test(),
                            s21_truncate_test(),
                            s21_negate_test(),
                            NULL};
  s21_Srunner(suite_18_func);
}

void s21_Srunner(Suite** suite) {
  for (int i = 0; suite[i];
       i++) {  // while suite is not NULL; last member of suites array is NULL
    SRunner* suite_runner = srunner_create(suite[i]);
    srunner_run_all(suite_runner, CK_NORMAL);
    srunner_free(suite_runner);
  }
}