#ifndef S21_UTILS_H_
#define S21_UTILS_H_

#include <stdbool.h>
#include <stddef.h>

#define LOOP_LIMIT 32

bool s21_isint(double x);
bool s21_isreal(double x);
bool s21_isodd(double x);
bool s21_iseven(double x);
bool s21_isnan(double x);
bool s21_isfinite(double x);
bool s21_isinf(double x);
bool s21_ispinf(double x);
bool s21_isninf(double x);
bool s21_signbit(double x);
bool s21_isnegative(double x);
bool s21_ispositive(double x);
void s21_print_bits(size_t size, void* ptr);
void s21_print_fp_sysinfo(void);
long double s21_trig_range_reduction(long double x);
long double s21_trunc(double x);
long double s21_factorial(int x);

#endif  // S21_UTILS_H_