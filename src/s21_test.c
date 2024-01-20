#include "s21_test.h"
//  TEST_ABS
START_TEST(s21_abs_test) {
  ck_assert_int_eq(s21_abs(INT_MIN), abs(INT_MIN));
  ck_assert_int_eq(s21_abs(-100), abs(-100));
  ck_assert_int_eq(s21_abs(-2), abs(-2));
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(1), abs(1));
  ck_assert_int_eq(s21_abs(2), abs(2));
  ck_assert_int_eq(s21_abs(100), abs(100));
  ck_assert_int_eq(s21_abs(INT_MAX), abs(INT_MAX));
}
END_TEST

//  TEST_FABS
START_TEST(s21_fabs_test) {
  check(s21_fabs(DBL_MIN), fabs(DBL_MIN));
  check(s21_fabs(-2.0), fabs(-2.0));
  check(s21_fabs(-1.0), fabs(-1.0));
  check(s21_fabs(-0.5), fabs(-0.5));
  check(s21_fabs(-0.0), fabs(-0.0));
  check(s21_fabs(0.0), fabs(0.0));
  check(s21_fabs(0.5), fabs(0.5));
  check(s21_fabs(1.0), fabs(1.0));
  check(s21_fabs(2.0), fabs(2.0));
  check(s21_fabs(DBL_MAX), fabs(DBL_MAX));
}
END_TEST

//  TEST_CEIL
START_TEST(s21_ceil_test) {
  check(s21_ceil(DBL_MIN), ceil(DBL_MIN));
  check(s21_ceil(-2.0), ceil(-2.0));
  check(s21_ceil(-1.5), ceil(-1.5));
  check(s21_ceil(-1.0), ceil(-1.0));
  check(s21_ceil(-0.5), ceil(-0.5));
  check(s21_ceil(-0.0), ceil(-0.0));
  check(s21_ceil(0.0), ceil(0.0));
  check(s21_ceil(0.5), ceil(0.5));
  check(s21_ceil(1.0), ceil(1.0));
  check(s21_ceil(1.5), ceil(1.5));
  check(s21_ceil(2.0), ceil(2.0));
  check(s21_ceil(DBL_MAX), ceil(DBL_MAX));
}
END_TEST

//  TEST_EXP
START_TEST(s21_exp_test) {
  check(s21_exp(-10), exp(-10));
  check(s21_exp(-1), exp(-1));
  check(s21_exp(-0.5), exp(-0.5));
  check(s21_exp(-0.0), exp(-0.0));
  check(s21_exp(0.0), exp(0.0));
  check(s21_exp(DBL_MIN), exp(DBL_MIN));
  check(s21_exp(0.5), exp(0.5));
  check(s21_exp(1), exp(1));
  check(s21_exp(10), exp(10));
  check(s21_exp(DBL_MAX), exp(DBL_MAX));
}
END_TEST

//  TEST_FLOOR
START_TEST(s21_floor_test) {
  check(s21_floor(-2.0), floor(-2.0));
  check(s21_floor(-1.0), floor(-1.0));
  check(s21_floor(-0.5), floor(-0.5));
  check(s21_floor(-0.0), floor(-0.0));
  check(s21_floor(0.0), floor(0.0));
  check(s21_floor(DBL_MIN), floor(DBL_MIN));
  check(s21_floor(DBL_MAX), floor(DBL_MAX));
  check(s21_floor(0.5), floor(0.5));
  check(s21_floor(1.0), floor(1.0));
  check(s21_floor(2.0), floor(2.0));
}
END_TEST

//  TEST_FMOD
START_TEST(s21_fmod_test) {
  check(s21_fmod(DBL_MAX, 2.0), fmod(DBL_MAX, 2.0));
  check(s21_fmod(DBL_MIN, 2.0), fmod(DBL_MIN, 2.0));
  check(s21_fmod(-1.0, -2.0), fmod(-1.0, -2.0));
  check(s21_fmod(-0.0, -2.0), fmod(-0.0, -2.0));
  check(s21_fmod(-1.0, 2.0), fmod(-1.0, 2.0));
  check(s21_fmod(-0.0, 2.0), fmod(-0.0, 2.0));
  check(s21_fmod(0.0, 2.0), fmod(0.0, 2.0));
  check(s21_fmod(2.0, -1.0), fmod(2.0, -1.0));
  check(s21_fmod(2.0, 1.0), fmod(2.0, 1.0));
  check(s21_fmod(2.0, DBL_MIN), fmod(2.0, DBL_MIN));
  check(s21_fmod(2.0, DBL_MAX), fmod(2.0, DBL_MAX));
}
END_TEST

//  TEST_LOG
START_TEST(s21_log_test) {
  check(s21_log(DBL_MIN), log(DBL_MIN));
  check(s21_log(1.234567), log(1.234567));
  check(s21_log(123456.7), log(123456.7));
  check(s21_log(0.5), log(0.5));
  check(s21_log(1.0), log(1.0));
  check(s21_log(2.25), log(2.25));
  check(s21_log(10.0), log(10.0));
  check(s21_log(100.0), log(100.0));
  check(s21_log(DBL_MAX), log(DBL_MAX));
}
END_TEST

//  TEST_POW
START_TEST(s21_pow_test) {
  check(s21_pow(2.0, -1.0), pow(2.0, -1.0));
  check(s21_pow(DBL_MIN, 2.0), pow(DBL_MIN, 2.0));
  check(s21_pow(-1.0, -2.0), pow(-1.0, -2.0));
  check(s21_pow(-1.0, 2.0), pow(-1.0, 2.0));
  check(s21_pow(-0.0, 2.0), pow(-0.0, 2.0));
  check(s21_pow(0.0, 0.0), pow(0.0, 0.0));
  check(s21_pow(2.0, -1.0), pow(2.0, -1.0));
  check(s21_pow(2.0, -0.0), pow(2.0, -0.0));
  check(s21_pow(2.0, 1.0), pow(2.0, 1.0));
  check(s21_pow(2.0, DBL_MIN), pow(2.0, DBL_MIN));
}
END_TEST

//  TEST_SQRT
START_TEST(s21_sqrt_test) {
  check(s21_sqrt(DBL_MIN), sqrt(DBL_MIN));
  check(s21_sqrt(-0.0), sqrt(-0.0));
  check(s21_sqrt(0.0), sqrt(0.0));
  check(s21_sqrt(0.5), sqrt(0.5));
  check(s21_sqrt(1.0), sqrt(1.0));
  check(s21_sqrt(2.25), sqrt(2.25));
  check(s21_sqrt(10.0), sqrt(10.0));
  check(s21_sqrt(100.0), sqrt(100.0));
  check(s21_sqrt(121), sqrt(121));
  check(s21_sqrt(DBL_MAX), sqrt(DBL_MAX));
}
END_TEST

//  TEST_SIN
START_TEST(s21_sin_test) {
  check(s21_sin(DBL_MIN), sin(DBL_MIN));
  check(s21_sin(-1.0 * s21_PI), sin(-1.0 * s21_PI));
  check(s21_sin(-1.0 * s21_PI / 2), sin(-1.0 * s21_PI / 2));
  check(s21_sin(-1.0 * s21_PI / 4), sin(-1.0 * s21_PI / 4));
  check(s21_sin(-0.0), sin(-0.0));
  check(s21_sin(0.0), sin(0.0));
  check(s21_sin(s21_PI / 4), sin(s21_PI / 4));
  check(s21_sin(s21_PI / 2), sin(s21_PI / 2));
  check(s21_sin(s21_PI), sin(s21_PI));
}
END_TEST

//  TEST_COS
START_TEST(s21_cos_test) {
  check(s21_cos(DBL_MIN), cos(DBL_MIN));
  check(s21_cos(-1.0 * s21_PI), cos(-1.0 * s21_PI));
  check(s21_cos(-1.0 * s21_PI / 2), cos(-1.0 * s21_PI / 2));
  check(s21_cos(-1.0 * s21_PI / 4), cos(-1.0 * s21_PI / 4));
  check(s21_cos(-0.0), cos(-0.0));
  check(s21_cos(0.0), cos(0.0));
  check(s21_cos(s21_PI / 4), cos(s21_PI / 4));
  check(s21_cos(s21_PI / 2), cos(s21_PI / 2));
  check(s21_cos(s21_PI), cos(s21_PI));
}
END_TEST

//  TEST_TAN
START_TEST(s21_tan_test) {
  check(s21_tan(DBL_MIN), tan(DBL_MIN));
  check(s21_tan(-2), tan(-2));
  check(s21_tan(-1.0 * s21_PI), tan(-1.0 * s21_PI));
  check(s21_tan(-1.0 * s21_PI / 4), tan(-1.0 * s21_PI / 4));
  check(s21_tan(-0.0), tan(-0.0));
  check(s21_tan(0.0), tan(0.0));
  check(s21_tan(s21_PI / 4), tan(s21_PI / 4));
  check(s21_tan(s21_PI), tan(s21_PI));
  check(s21_tan(2), tan(2));
}
END_TEST

//  TEST_ASIN
START_TEST(s21_asin_test) {
  check(s21_asin(DBL_MIN), asin(DBL_MIN));
  check(s21_asin(-0.9), asin(-0.9));
  check(s21_asin(-0.5), asin(-0.5));
  check(s21_asin(-0.0), asin(-0.0));
  check(s21_asin(0.0), asin(0.0));
  check(s21_asin(-1.0), asin(-1.0));
  check(s21_asin(0.5), asin(0.5));
  check(s21_asin(0.9), asin(0.9));
  check(s21_asin(1.0), asin(1.0));
  check(s21_asin(DBL_MAX), asin(DBL_MAX));
}
END_TEST

//  TEST_ACOS
START_TEST(s21_acos_test) {
  check(s21_acos(DBL_MIN), acos(DBL_MIN));
  check(s21_acos(-0.9), acos(-0.9));
  check(s21_acos(-0.5), acos(-0.5));
  check(s21_acos(-0.0), acos(-0.0));
  check(s21_acos(0.0), acos(0.0));
  check(s21_acos(-1.0), acos(-1.0));
  check(s21_acos(0.5), acos(0.5));
  check(s21_acos(0.9), acos(0.9));
  check(s21_acos(1.0), acos(1.0));
  check(s21_acos(DBL_MAX), acos(DBL_MAX));
}
END_TEST

//  TEST_ATAN
START_TEST(s21_atan_test) {
  check(s21_atan(DBL_MIN), atan(DBL_MIN));
  check(s21_atan(-2.0), atan(-2.0));
  check(s21_atan(-1.5), atan(-1.5));
  check(s21_atan(-1.0), atan(-1.0));
  check(s21_atan(-0.5), atan(-0.5));
  check(s21_atan(-0.0), atan(-0.0));
  check(s21_atan(0.0), atan(0.0));
  check(s21_atan(0.5), atan(0.5));
  check(s21_atan(1.0), atan(1.0));
  check(s21_atan(1.5), atan(1.5));
  check(s21_atan(2.0), atan(2.0));
  check(s21_atan(DBL_MAX), atan(DBL_MAX));
}
END_TEST

void check(long double s21, long double math) {
  if (isnan(s21) && isnan(math)) {
    ck_assert_double_nan(s21);
    ck_assert_double_nan(math);
  } else if (s21 == math) {
    ck_assert_double_eq(s21, math);
  } else if (s21 > s21_ACCURACY * OVERALL_ACCURACY) {
    long double s21_a = s21 / OVERALL_ACCURACY;
    long double math_a = s21 / OVERALL_ACCURACY;
    ck_assert_double_eq_tol(s21_a, math_a, s21_ACCURACY);
  } else {
    ck_assert_double_eq_tol(s21, math, s21_ACCURACY);
  }
}

Suite *add_test(Suite *suite, const TTest *test) {
  TCase *test_case = tcase_create(test->name);
  tcase_add_test(test_case, test);
  suite_add_tcase(suite, test_case);
  return suite;
}

void tests_runner(SRunner *runner) {
  s21_abs_tester(runner);
  s21_fabs_tester(runner);
  s21_asin_tester(runner);
  s21_acos_tester(runner);
  s21_atan_tester(runner);
  s21_sin_tester(runner);
  s21_cos_tester(runner);
  s21_tan_tester(runner);
  s21_ceil_tester(runner);
  s21_exp_tester(runner);
  s21_floor_tester(runner);
  s21_fmod_tester(runner);
  s21_log_tester(runner);
  s21_pow_tester(runner);
  s21_sqrt_tester(runner);
}

void s21_abs_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_abs_test...");
  tests = add_test(tests, s21_abs_test);
  srunner_add_suite(runner, tests);
}

void s21_fabs_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_fabs_test...");
  tests = add_test(tests, s21_fabs_test);
  srunner_add_suite(runner, tests);
}

void s21_ceil_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_ceil_test...");
  tests = add_test(tests, s21_ceil_test);
  srunner_add_suite(runner, tests);
}

void s21_exp_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_exp_test...");
  tests = add_test(tests, s21_exp_test);
  srunner_add_suite(runner, tests);
}

void s21_floor_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_floor_test...");
  tests = add_test(tests, s21_floor_test);
  srunner_add_suite(runner, tests);
}

void s21_fmod_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_fmod_test...");
  tests = add_test(tests, s21_fmod_test);
  srunner_add_suite(runner, tests);
}

void s21_log_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_log_test...");
  tests = add_test(tests, s21_log_test);
  srunner_add_suite(runner, tests);
}

void s21_pow_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_pow_test...");
  tests = add_test(tests, s21_pow_test);
  srunner_add_suite(runner, tests);
}

void s21_sqrt_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_sqrt_test...");
  tests = add_test(tests, s21_sqrt_test);
  srunner_add_suite(runner, tests);
}

void s21_sin_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_sin_test...");
  tests = add_test(tests, s21_sin_test);
  srunner_add_suite(runner, tests);
}

void s21_cos_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_cos_test...");
  tests = add_test(tests, s21_cos_test);
  srunner_add_suite(runner, tests);
}

void s21_tan_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_tan_test...");
  tests = add_test(tests, s21_tan_test);
  srunner_add_suite(runner, tests);
}

void s21_asin_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_asin_test...");
  tests = add_test(tests, s21_asin_test);
  srunner_add_suite(runner, tests);
}

void s21_acos_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_acos_test...");
  tests = add_test(tests, s21_acos_test);
  srunner_add_suite(runner, tests);
}

void s21_atan_tester(SRunner *runner) {
  Suite *tests = suite_create("Running s21_atan_test...");
  tests = add_test(tests, s21_atan_test);
  srunner_add_suite(runner, tests);
}

int main() {
  SRunner *runner = srunner_create(suite_create(""));
  tests_runner(runner);
  srunner_set_log(runner, "s21_math_test.log");
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
  return 0;
}
