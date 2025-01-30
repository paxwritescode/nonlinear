#include "EulerMethod.h"
#include "constants.h"

double *EulerMethod(double a, double b, double h, double t, double (*f)(double, double, int))
{
    double cur_x = a;
    double *y_res = NULL;

    y_res = (double *)calloc((b - a) / h + 1, sizeof(double));
    y_res[0] = Y_0;

    int i = 1;

    while (cur_x <= b)
    {
        y_res[i] = y_res[i - 1] + h * f(cur_x, y_res[i - 1], t);
        i++;
        cur_x += h;
    }

    return y_res;
}