#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdio.h>

#define S21_SIGN_BIT 127
#define EPS 1e-6
#define S21_STATUS_OK 0
#define S21_STATUS_ERROR_LARGE 1
#define S21_STATUS_ERROR_SMALL 2
#define S21_STATUS_ERROR_DIV_BY_ZERO 3

#define S21_STATUS_CONVERT_OK 0
#define S21_STATUS_CONVERT_ERROR 1

#define S21_MAX_DECIMAL 79228162514264337593543950335.0
#define S21_MIN_DECIMAL 1e-28
#define S21_MAX_INT 2147483647
#define S21_MIN_INT -2147483648

#define S21_MAX_UINT 4294967295

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[6];
  unsigned int scale;
  unsigned int sign;
} big_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

#define OK 0
#define INF_POS 1
#define INF_NEG 2
#define DIV_BY_ZERO 3
#define MINUS 0x80000000
#define SCALE 0x00ff0000

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_add_no_drop(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);
void s21_add_pos_pos(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result, int *b_ten);
void add_sign_logic(int sign_value1, int sign_value2, s21_decimal value_1,
                    s21_decimal value_2, s21_decimal *result, int *b_ten);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_sub_pos_pos(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int s21_div_by_ten(s21_decimal value, s21_decimal *result);
void degree_normalization(s21_decimal *value_1, s21_decimal *value_2);
void s21_decimal_init(s21_decimal *value);
void s21_decimal_init_decimal(s21_decimal *value, s21_decimal src);
void s21_decimal_init_int(s21_decimal *value, long long int x);
int s21_get_bit(s21_decimal value, unsigned int i);
void s21_set_bit(s21_decimal *value, unsigned int bit, unsigned int i);

void s21_set_bit_one(s21_decimal *value, unsigned int i);
void s21_set_bit_zero(s21_decimal *value, unsigned int i);

int s21_get_bit_int(long long int value, unsigned int i);

int s21_get_degree(s21_decimal value);
void s21_set_degree(s21_decimal *value, int degree);

int s21_count_sign_digits_int_part(float x);
int s21_define_degree(double src);
void s21_remove_extra_zeros(long int *number, int pow_degree);

void s21_multy_by_shift_decimal_ten(s21_decimal *src);
void s21_multy_by_shift_decimal_degree(s21_decimal *src, int degree);
void s21_remove_extra_zeros(long int *number, int pow_degree);

int s21_define_count_decimal_digits(s21_decimal d);
void s21_divide_by_ten_dec(s21_decimal *dec);
void s21_division_after_different_degrees(s21_big_decimal *result, int n_degree,
                                          int *d);
void s21_drop_fract_zero(s21_decimal *value);
int s21_last_digit_number_decimal(s21_decimal dec);
void s21_division_into_column(s21_decimal value_1, s21_decimal value_2,
                              s21_big_decimal *b_dec, int count_dig_value_1,
                              int count_dig_value_2, int *count_n,
                              int *count_decimal_digits, int *degree);
int s21_is_zero_decimal(s21_decimal value);
int s21_define_binary_digits(s21_decimal value);

void setbit_pos(s21_decimal *dec, int bit, int pos);
int getbit_pos(s21_decimal dec, int pos);
void make_zero_all_bits(s21_decimal *dec);
void shift_left_bits(s21_decimal *dec);
void convertation_in_big_decimal(s21_decimal dec, big_decimal *big_dec);
void convertation_in_decimal(big_decimal big_dec, s21_decimal *dec);
int check_for_zero(s21_decimal dec);
int last_digit_number_decimal(s21_decimal dec);
void s21_div_by_ten_dec(s21_decimal *dec);
void drop_fract_zero(s21_decimal *value);

void setbit_pos_bigdec(big_decimal *dec, int bit, int pos);
int getbit_pos_bigdec(big_decimal dec, int pos);
void make_zero_all_bits_bigdec(big_decimal *dec);
void shift_left_bits_bigdec(big_decimal *dec);
void divide_by_ten_big_dec(big_decimal *dec);
int last_digit_number(big_decimal dec);
int get_big_degree(big_decimal value);
void add_one_with_big_dec(big_decimal *dec);
void daily_addition(big_decimal value_1, big_decimal value_2,
                    big_decimal *result);
void reduction_number_bigdec(big_decimal *value, int *degree, int *penult_num,
                             int *round_num);
void bank_round(big_decimal *value, int *degree, int *penult_num,
                int *round_num);

void print_decimal(s21_decimal dec);
void print_big_decimal(big_decimal big_dec);

void s21_big_decimal_init(s21_big_decimal *value);
void s21_big_decimal_init_decimal(s21_big_decimal *value, s21_decimal src);
void s21_div_by_shift_big_decimal(s21_big_decimal *src);
void s21_multy_by_shift_big_decimal_ten(s21_big_decimal *src);
void s21_multy_by_shift_big_decimal_degree(s21_big_decimal *src, int degree);
void s21_big_decimal_init_big_decimal(s21_big_decimal *value,
                                      s21_big_decimal src);
int s21_big_decimal_add(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);
int s21_big_decimal_get_bit(s21_big_decimal value, unsigned int i);
void s21_big_decimal_set_bit(s21_big_decimal *value, unsigned int bit,
                             unsigned int i);
void s21_big_decimal_add_pos_pos(s21_big_decimal value_1,
                                 s21_big_decimal value_2,
                                 s21_big_decimal *result, int *b_ten);
void s21_decimal_init_big_decimal(s21_decimal *value, s21_big_decimal src);
void s21_divide_by_ten_big_dec(s21_big_decimal *dec);
int s21_last_digit_number_big_decimal(s21_big_decimal dec);
void s21_add_one_with_big_dec(s21_big_decimal *dec);
void s21_big_decimal_round(s21_big_decimal *b_dec, int *degree);
int s21_getbit_pos_bigdec(s21_big_decimal dec, int pos);
void s21_big_decimal_bank_round(s21_big_decimal *b_dec, int last_number);
int s21_is_zero_big_decimal(s21_big_decimal value);

#endif
