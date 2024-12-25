#include "EulerMethod.h"
#include "constants.h"

double* EulerMethod(double a, double b, double h, double t, double (*f)(double, double, double))
{
    double cur_x = a + h;
    double* y_res = NULL;

    y_res = (double*)calloc((b - a) / h, sizeof(double));
    y_res[0] = y_0;

    int i = 1;

    while (cur_x <= b)
    {
        y_res[i] = y_res[i - 1] + h * f(cur_x - h, y_res[i - 1], t);
        i++;
        cur_x += h;
    }

    return y_res;
}