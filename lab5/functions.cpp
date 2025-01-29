#include "functions.h"

double f(double x, double y, int t)
{
    return y * cos(t * x);
}

double y_exact(double x, int t)
{
    return exp(sin(t * x)) / t;
}