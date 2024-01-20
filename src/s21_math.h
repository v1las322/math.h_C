#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#define s21_NAN 0.0 / 0.0
#define s21_INFINITY 1.0 / 0.0
#define s21_EXP 2.718281828459
#define s21_PI 3.141592653590
#define s21_ACCURACY 1e-07
#define OVERALL_ACCURACY 1e-17

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exponent);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
int s21_isInfinity(double x);
int s21_isPositive(double x);

#endif  // SRC_S21_MATH_H_