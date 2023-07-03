#include "s21_fp_utils.h"
#include "s21_math.h"

// through atan
long double s21_asin(double x) {
  const double SYSTEMLIB_SIN_PI_4 = 0.70710678118654746;

  if (x < -1.0 || 1.0 < x) {
    return +S21_FP_NAN;
  }
  if (x == +1.0) {
    return +S21_PI_2;
  }
  if (x == -1.0) {
    return -S21_PI_2;
  }
  if (x == +SYSTEMLIB_SIN_PI_4) {
    return +S21_PI_4;
  }
  if (x == -SYSTEMLIB_SIN_PI_4) {
    return -S21_PI_4;
  }

  return s21_atan((double)((long double)x / s21_sqrt(1 - x * x)));
}