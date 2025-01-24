#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

void PrintTwoSidedRungeKuttaSolution(double h, int t, double(*f)(double, double, int));
