#include "s21_fp_utils.h"
#include "s21_math.h"

// through atan
long double s21_acos(double x) {
  const double SYSTEMLIB_COS_PI_4 = 0.70710678118654752;
  const double SYSTEMLIB_COS_3_PI_4 = -0.70710678118654746;

  if (x < -1.0 || 1.0 < x) {
    return S21_FP_NAN;
  }
  if (x == +1.0) {
    return 0.0L;
  }
  if (x == -1.0) {
    return S21_PI;
  }
  if (x == 0.0) {
    return S21_PI_2;
  }
  if (x == SYSTEMLIB_COS_PI_4) {
    return S21_PI_4;
  }
  if (x == SYSTEMLIB_COS_3_PI_4) {
    return S21_PI - S21_PI_4;
  }

  long double res = s21_atan((double)(s21_sqrt(1 - x * x) / (long double)x));

  if (-1.0 < x && x < 0.0) {
    res = res + S21_PI;
  }

  return res;
}