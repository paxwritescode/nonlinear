#include <iostream>

#include "EulerMethod.h"
#include "constants.h"
#include "functions.h"

int main(void)
{
   double* EulerResult = EulerMethod(A, B, h_1, t_1, f);
   int N = int((B - A) / h_1);
   for (int i = 0; i < N; i++)
   {
    std::cout << EulerResult[i] << ", ";
   }
}