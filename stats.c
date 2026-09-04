#include "stats.h"
#define _USE_MATH_DEFINES
#include <math.h>

float cauchy(float x)
{
    x = 1 / (M_PI * (1 + x * x));

    return x;
}

float gumbel(float x, float mu, float beta)
{
    float y, z;

    z = (x - mu) / beta;

    y = (1 / beta) * exp(-(z + exp(-z)));

    return y;
}

float laplace(float x, float mu, float b)
{
    float f;

    f = (1 / (2 * b)) * exp((-1 / b) * fabs(x - mu));

    return f;
}