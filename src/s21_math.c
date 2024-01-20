#include "s21_math.h"

#include <float.h>

int s21_abs(int x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}

long double s21_fabs(double x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}

long double s21_sin(double x) {
  int sign = (x < 0) ? -1 : 1;
  x = s21_fmod(s21_fabs(x), 2 * s21_PI);
  if (x > s21_PI) {
    x -= s21_PI;
    sign *= -1;
  }
  if (x > s21_PI / 2) x = s21_PI - x;
  double tmp = x, sin = x;
  for (int n = 3; s21_fabs(tmp) > s21_ACCURACY; n += 2)
    sin += tmp = -tmp * x * x / n / (n - 1);
  return sin * sign;
}

long double s21_cos(double x) { return (s21_sin(s21_PI / 2 + x)); }

long double s21_tan(double x) { return (s21_sin(x) / s21_cos(x)); }

long double s21_atan(double x) {
  long double atan = 0, tmp_x = x, sign = 1;
  if (x < 0) {
    tmp_x *= -1;
  }
  if (s21_fabs(x) > 1) {
    tmp_x = 1 / tmp_x;
  }
  long double tmp = tmp_x;
  long double improvisedpow = tmp_x;
  for (long double n = 3; s21_fabs(tmp) > s21_ACCURACY; n += 2) {
    atan += tmp;
    sign *= -1;
    improvisedpow *= tmp_x * tmp_x;
    tmp = sign * improvisedpow / n;
  }
  if (s21_fabs(x) > 1) atan = s21_PI / 2 - atan;
  if (x < 0) {
    atan = -atan;
  }
  return atan;
}

long double s21_asin(double x) {
  long double asin = s21_NAN;
  if (x > -1 && x < 1) {
    asin = s21_atan((double)x / s21_sqrt((1 - (x * x))));
  } else if (x == -1 || x == 1) {
    asin = s21_PI / (2 * x);
  }
  return asin;
}

long double s21_acos(double x) {
  long double acos = s21_NAN;
  if (x >= -1 && x <= 1) {
    acos = s21_PI / 2 - s21_asin(x);
  }
  return acos;
}

long double s21_ceil(double x) {
  long double check;
  if (s21_isInfinity(x) == 1) {
    check = s21_INFINITY;
  } else if (s21_isInfinity(x) == -1) {
    check = -s21_INFINITY;
  } else if (x == DBL_MAX) {
    check = x;
  } else if (x == DBL_MIN) {
    check = 1;
  } else {
    if (x == (int)x || x < 0) {
      check = (int)x;
    } else {
      check = (int)x + 1;
    }
  }
  return (check);
}

long double s21_floor(double x) {
  long double check;
  if (s21_isInfinity(x) == 1) {
    check = s21_INFINITY;
  } else if (s21_isInfinity(x) == -1) {
    check = -s21_INFINITY;
  } else if (x == DBL_MAX || x == DBL_MIN) {
    check = x;
  } else {
    if (x == (int)x || x > 0) {
      check = (int)x;
    } else {
      check = (int)x - 1;
    }
  }
  return (check);
}

int s21_isInfinity(double x) {
  int flag = 0;
  if (s21_isPositive(x) == 1) {
    if (x == s21_INFINITY) flag = 1;
  } else {
    if ((x * -1) == s21_INFINITY) flag = -1;
  }
  return flag;
}

int s21_isPositive(double x) {
  int flag = 0;
  if (x > 0) flag = 1;
  return flag;
}

long double s21_sqrt(double x) {
  long double result = x;
  if (x < 0) {
    result = s21_NAN;
  } else if (x == 0.0 || x == 1.0) {
    result = x;
  } else {
    while (s21_fabs(result * result - x) > s21_ACCURACY) {
      result = (result + x / result) / 2;
    }
  }
  return result;
}

long double s21_fmod(double x, double y) {
  if (y == 0 || y == s21_NAN || x == s21_NAN) {
    x = s21_NAN;
  } else if (y == DBL_MIN || x == DBL_MAX) {
    x = 0.0;
  } else if (x / y < 0) {
    x = x - s21_ceil(x / y) * y;
  } else {
    x = x - s21_floor(x / y) * y;
  }
  return x;
}

long double s21_log(double x) {
  long double result = 0.0;
  if (x == s21_NAN || x < 0.0) {
    result = s21_NAN;
  } else if (x == 0.0) {
    result = -s21_INFINITY;
  } else if (x == 1.0) {
    result = 0;
  } else if (x == DBL_MIN) {
    result = -s21_log(1.0 / DBL_MIN);
  } else {
    long double elem = 0.0;
    int count = 0;
    while (x >= 2) {
      count++;
      x /= s21_EXP;
    }
    x = x - 1;
    result = elem = x;
    for (int i = 2; s21_fabs(elem) > s21_ACCURACY; i++) {
      elem *= -((i - 1) * (x / i));
      result += elem;
    }
    result += count;
  }
  return result;
}

long double s21_pow(double base, double exp) {
  long double result = 0.0;
  if (base == 0 && exp < 0) {
    result = s21_INFINITY;
  } else if (exp == 0) {
    result = 1;
  } else if (exp == 1) {
    result = base;
  } else {
    int flag = 1;
    if (exp < 0) {
      exp = -exp;
      flag = 0;
    }
    long double term = 1.0;
    long double delta = exp * s21_log(base);
    unsigned den = 1;
    while (term > s21_ACCURACY) {
      result += term;
      term *= delta / (den++);
    }
    if (!flag) {
      result = 1.0 / result;
    }
  }
  return result;
}
long double s21_exp(double x) {
  long double result;
  if (x == 0.0) {
    result = 1.0;
  } else {
    int flag = 1;
    if (x < 0) {
      x = -x;
      flag = 0;
    }
    long double sum = 1.0;
    long double term = 1.0;
    for (int i = 1; term < s21_ACCURACY; i++) {
      term *= x / i;
      sum += term;
    }
    if (!flag) {
      result = 1 / sum;
    } else {
      result = sum;
    }
  }
  return result;
}
