#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

struct real
{
  int real_number;
};

// #define REAL_NUMBER(REAL) REAL.real_number
//
// #define FIXED_POINT(INTEGER) { INTEGER * F }
//
// #define ZERO_ROUNDING(REAL)  REAL_NUMBER(REAL) / F
//
// #define NEAREST_ROUNDING(REAL)  #if REAL_NUMBER(REAL) >= 0
//                                    (REAL_NUMBER(REAL) + F) / 2
//                                 #endif


struct real fixed_point (int integer);

int zero_rounding (struct real real_num);

int nearest_rounding (struct real real_num);

struct real add_fixed_point (struct real x, struct real y);

struct real increment_fixed_point (struct real x);

struct real subtract_fixed_point (struct real x, struct real y);

struct real add_integer (struct real x, int n);

struct real subtract_integer (struct real x, int n);

struct real multiply_fixed_point (struct real x, struct real y);

struct real multiply_integer (struct real x, int n);

struct real divide_fixed_point (struct real x, struct real y);

struct real divide_integer (struct real x, int n);
#endif
