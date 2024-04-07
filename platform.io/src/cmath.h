/*
 * Rad Pro
 * Compact math
 *
 * (C) 2022-2024 Gissio
 *
 * License: MIT
 */

#if !defined(CMATH_H)
#define CMATH_H

#include <stdbool.h>
#include <stdint.h>

#if defined(SIMULATOR)

#include <math.h>

inline float exp10f(float x)
{
    return powf(10.0F, x);
}

#else

float logf(float x);
float log2f(float x);
float log10f(float x);
float expf(float x);
float exp2f(float x);
float exp10f(float x);
float powf(float x, float y);
float sqrtf(float x);

#endif

void addClamped(uint32_t *x, uint32_t y);

float getConfidenceInterval(uint32_t n);

bool getRandomBit(void);

#endif
