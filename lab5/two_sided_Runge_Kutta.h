#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

void PrintTwoSidedRungeKuttaSolution(double h, int t, double(*f)(double, double, int), std::ofstream& outFile);