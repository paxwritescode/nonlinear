#include <iostream>

#include "EulerMethod.h"
#include "constants.h"
#include "functions.h"
#include "two_sided_Runge_Kutta.h"

int main(void)
{
   std::cout << std::endl << std::endl;

   std::cout << "Two Sided Runge-Kutta Method, h = " << std::endl;

   PrintTwoSidedRungeKuttaSolution(H_0, T_1, f);
}