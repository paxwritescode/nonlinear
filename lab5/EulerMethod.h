#pragma once

#include <cstdlib>

double* EulerMethod(double a, double b, double h, double t, double (*f)(double, double, int));