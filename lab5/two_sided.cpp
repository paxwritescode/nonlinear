#include "two_sided.h"
#include "constants.h"

double *Compute3K(double x, double y, double t, double h, double alpha_2, double alpha_3, double beta_21, double beta_31, double beta_32, double (*f)(double, double, double))
{
    double *K = nullptr;
    K = (double*)calloc(3, sizeof(double));
    if (K == nullptr)
        exit(MEMORY_NOT_ALLOCATED);
    
    K[0] = f(x, y, t);
    K[1] = f(x + h * alpha_2, y + h * beta_21 * K[0], t);
    K[3] = f(x + h * alpha_3, y + h * (beta_31 * K[0] + beta_32 * K[1]), t);


    return K;
}