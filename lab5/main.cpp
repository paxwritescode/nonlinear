#include <iostream>

#include "EulerMethod.h"
#include "constants.h"
#include "functions.h"

int main(void)
{
   double* EulerResult = EulerMethod(A, B, H_1, T_1, f);
   int N = int((B - A) / H_1);
   for (int i = 0; i < N; i++)
   {
    std::cout << EulerResult[i] << ", ";
   }
}