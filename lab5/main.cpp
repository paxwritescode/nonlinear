#include <iostream>

#include "EulerMethod.h"
#include "constants.h"
#include "functions.h"
#include "two_sided_Runge_Kutta.h"

int main(void)
{
   std::cout << "Two Sided Runge-Kutta Method, h = " << H_TEST << std::endl;

   PrintTwoSidedRungeKuttaSolution(H_TEST, T_1, f);

   std::cout << std::endl << std::endl;

   std::cout << "Two Sided Runge-Kutta Method, h = " << H_0 << std::endl;

   PrintTwoSidedRungeKuttaSolution(H_0, T_1, f);

   std::cout << std::endl << std::endl;

   std::cout << "Two Sided Runge-Kutta Method, h = " << H_1 << std::endl;

   PrintTwoSidedRungeKuttaSolution(H_1, T_1, f);

   std::cout << std::endl << std::endl;

   std::cout << "Two Sided Runge-Kutta Method, h = " << H_2 << std::endl;

   PrintTwoSidedRungeKuttaSolution(H_2, T_1, f);

}