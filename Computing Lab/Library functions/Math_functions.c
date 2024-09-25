
// The <math.h> header in C provides a variety of functions for mathematical computations. Here’s a list of common functions provided in the math.h library:

// 1. Basic Arithmetic Functions:
// double sqrt(double x) — Square root of x.
// double pow(double base, double exponent) — Base raised to the power of the exponent.
// double cbrt(double x) — Cube root of x.
// double hypot(double x, double y) — Returns the square root of (x^2 + y^2) without overflow or underflow.

// 2. Trigonometric Functions:
// double sin(double x) — Sine of x (in radians).
// double cos(double x) — Cosine of x (in radians).
// double tan(double x) — Tangent of x (in radians).
// double asin(double x) — Arc sine (inverse sine) of x (returns result in radians).
// double acos(double x) — Arc cosine (inverse cosine) of x (in radians).
// double atan(double x) — Arc tangent (inverse tangent) of x (in radians).
// double atan2(double y, double x) — Arc tangent of y/x, considering the quadrant.

// 3. Hyperbolic Functions:
// double sinh(double x) — Hyperbolic sine of x.
// double cosh(double x) — Hyperbolic cosine of x.
// double tanh(double x) — Hyperbolic tangent of x.
// double asinh(double x) — Inverse hyperbolic sine of x.
// double acosh(double x) — Inverse hyperbolic cosine of x.
// double atanh(double x) — Inverse hyperbolic tangent of x.

// 4. Exponential and Logarithmic Functions:
// double exp(double x) — Exponential function (e^x).
// double exp2(double x) — Returns 2 raised to the power of x.
// double log(double x) — Natural logarithm of x (base e).
// double log10(double x) — Common logarithm of x (base 10).
// double log2(double x) — Base-2 logarithm of x.
// double log1p(double x) — Returns log(1 + x) accurately even for small values of x.
// double expm1(double x) — Returns exp(x) - 1, useful for small x.

// 5. Power and Remainder Functions:
// double fmod(double x, double y) — Floating-point remainder of x/y.
// double remainder(double x, double y) — Returns the remainder of x/y.
// double remquo(double x, double y, int *quo) — Remainder and part of the quotient.
// double ldexp(double x, int exp) — Multiplies x by 2 raised to the power exp.
// double frexp(double x, int *exp) — Breaks x into normalized fraction and an exponent.

// 6. Absolute Value and Sign Manipulation:
// double fabs(double x) — Absolute value of x.
// double copysign(double x, double y) — Returns x with the sign of y.
// double fdim(double x, double y) — Positive difference between x and y (x - y if x > y, otherwise 0).
// double fmax(double x, double y) — Maximum of x and y.
// double fmin(double x, double y) — Minimum of x and y.

// 7. Rounding Functions:
// double ceil(double x) — Rounds x upward to the nearest integer.
// double floor(double x) — Rounds x downward to the nearest integer.
// double round(double x) — Rounds x to the nearest integer, halfway cases away from zero.
// double trunc(double x) — Truncates x to the integer part by removing the fractional part.
// double nearbyint(double x) — Rounds x to an integer using the current rounding mode.
// long int lround(double x) — Rounds x to the nearest integer and returns it as a long integer.

// 8. Floating-Point Classification Functions:
// int isfinite(double x) — Checks if x is finite.
// int isinf(double x) — Checks if x is infinity.
// int isnan(double x) — Checks if x is a NaN (Not a Number).
// int isnormal(double x) — Checks if x is a normal floating-point number.
// int signbit(double x) — Checks if the sign bit of x is set (if x is negative).

// 9. Gamma and Related Functions:
// double tgamma(double x) — Gamma function of x.
// double lgamma(double x) — Natural logarithm of the absolute value of the Gamma function of x.

// 10. Error and Special Functions:
// double erf(double x) — Error function.
// double erfc(double x) — Complementary error function.
// double nextafter(double x, double y) — Next representable floating-point value after x in the direction of y.
// double nexttoward(double x, long double y) — Next representable floating-point value after x toward y.
// Note:
// For each of these functions, there are also versions for float and long double types:

// For float type, append an f (e.g., sqrtf for square root of a float).
// For long double type, append an l (e.g., sqrtl for square root of a long double).