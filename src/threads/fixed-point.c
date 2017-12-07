#include "fixed-point.h"
#include <stdint.h>


const int F = 16384;

struct real fixed_point (int integer)
{
  struct real real_converted_number = { integer * F };
  return real_converted_number;
}

int zero_rounding (struct real real_num)
{
  return real_num.real_number / F;
}

int nearest_rounding (struct real real_num)
{
  if (real_num.real_number > 0)
    return (real_num.real_number + F / 2) / F;
  return (real_num.real_number - F / 2) / F;
}

struct real add_fixed_point (struct real x, struct real y)
{
  struct real real_converted_number = { x.real_number + y.real_number };
  return real_converted_number;
}

struct real increment_fixed_point (struct real x)
{
  return add_integer (x, 1);
}

struct real subtract_fixed_point (struct real x, struct real y)
{
  struct real real_converted_number = { x.real_number - y.real_number };
  return real_converted_number;
}

struct real add_integer (struct real x, int n)
{
  struct real real_converted_number = { x.real_number + n * F };
  return real_converted_number;
}

struct real subtract_integer (struct real x, int n)
{
  struct real real_converted_number = { x.real_number - n * F };
  return real_converted_number;
}

struct real multiply_fixed_point (struct real x, struct real y)
{
  struct real real_converted_number = { ((int64_t) x.real_number)
                                            * y.real_number / F };
  return real_converted_number;
}

struct real multiply_integer (struct real x, int n)
{
  struct real real_converted_number = { x.real_number * n };
  return real_converted_number;
}

struct real divide_fixed_point (struct real x, struct real y)
{
  struct real real_converted_number = { ((int64_t) x.real_number)
                                            * F / y.real_number };
  return real_converted_number;
}

struct real divide_integer (struct real x, int n)
{
  struct real real_converted_number = { x.real_number / n };
  return real_converted_number;
}
