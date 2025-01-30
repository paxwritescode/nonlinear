#include <iostream>
#include <fstream>

#include "EulerMethod.h"
#include "constants.h"
#include "functions.h"
#include "two_sided_Runge_Kutta.h"

void DoEuler(double h, int t, std::ofstream &outFile)
{
   double *EulerRes = EulerMethod(A, B, h, t, f);
   int n = int((B - A) / h);
   outFile << "Euler Method, h = " << h << ", t = " << t << std::endl;
   for (int i = 0; i <= n; i++)
   {
      outFile << EulerRes[i] << ", ";
   }
   outFile << std::endl;
   outFile << "Numerical Error" << std::endl;
   for (int i = 0; i <= n; i++)
   {
      outFile << fabs(EulerRes[i] - y_exact(A + i * h, t)) << ", ";
   }
   outFile << std::endl
           << std::endl;
   free(EulerRes);
}

void DoTwoSidedRungeKutta(double h, int t, std::ofstream &outFile)
{
   outFile << "Two Sided Runge-Kutta Method, h = " << h << ", t = " << t << std::endl;

   PrintTwoSidedRungeKuttaSolution(h, t, f, outFile);

   outFile << std::endl
           << std::endl;
}

int main(void)
{
   // Two Sided

   std::ofstream TwoSidedOutFile("TwoSidedOut.txt");

   DoTwoSidedRungeKutta(H_1, T_1, TwoSidedOutFile);
   DoTwoSidedRungeKutta(H_2, T_1, TwoSidedOutFile);
   DoTwoSidedRungeKutta(H_3, T_1, TwoSidedOutFile);
   DoTwoSidedRungeKutta(H_1, T_2, TwoSidedOutFile);
   DoTwoSidedRungeKutta(H_2, T_2, TwoSidedOutFile);
   DoTwoSidedRungeKutta(H_3, T_2, TwoSidedOutFile);

   std::cout << "Two Sided RUnge-Kutta: done" << std::endl;

   TwoSidedOutFile.close();

   // Euler

   std::ofstream EulerOutFile("EulerOut.txt");

   DoEuler(H_1, T_1, EulerOutFile);
   DoEuler(H_2, T_1, EulerOutFile);
   DoEuler(H_3, T_1, EulerOutFile);
   DoEuler(H_1, T_2, EulerOutFile);
   DoEuler(H_2, T_2, EulerOutFile);
   DoEuler(H_3, T_2, EulerOutFile);

   EulerOutFile.close();
   std::cout << "Euler: done" << std::endl;
}