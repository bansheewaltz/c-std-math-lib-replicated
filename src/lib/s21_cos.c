#include "s21_fp_utils.h"
#include "s21_fp_utilsl.h"
#include "s21_math.h"

// through Taylor series
long double s21_cos(double x) {
  if (s21_isnan(x)) {
    return S21_FP_NAN;
  }
  if (s21_isinf(x)) {
    return S21_FP_NAN;
  }

  long double inp = s21_trig_range_reduction((long double)x);

  long double ith_term = 1;  // 1 is the zeroth term
  long double partial_sum = ith_term;

  int i = 1;
  while (s21_fabsl(ith_term) > S21_EPSILON) {
    ith_term = -ith_term * inp * inp / ((2 * i) * (2 * i - 1));
    partial_sum += ith_term;
    ++i;

    if (i >= LOOP_LIMIT) {
      break;
    }
  }

  return partial_sum;
}