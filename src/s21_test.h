#ifndef SRC_S21_TEST_H_
#define SRC_S21_TEST_H_
#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"
Suite *add_test(Suite *suite, const TTest *test);
void check(long double s21, long double math);
void tests_runner(SRunner *runner);
void s21_abs_tester(SRunner *runner);
void s21_fabs_tester(SRunner *runner);
void s21_asin_tester(SRunner *runner);
void s21_acos_tester(SRunner *runner);
void s21_atan_tester(SRunner *runner);
void s21_sin_tester(SRunner *runner);
void s21_cos_tester(SRunner *runner);
void s21_tan_tester(SRunner *runner);
void s21_ceil_tester(SRunner *runner);
void s21_exp_tester(SRunner *runner);
void s21_floor_tester(SRunner *runner);
void s21_fmod_tester(SRunner *runner);
void s21_log_tester(SRunner *runner);
void s21_pow_tester(SRunner *runner);
void s21_sqrt_tester(SRunner *runner);

#endif  // SRC_S21_TEST_H_
