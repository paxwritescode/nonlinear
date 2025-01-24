#include "two_sided_Runge_Kutta.h"
#include "constants.h"

double RungeKuttaScheme1(double x, double y, double h, int t, double(*f)(double, double, int))
{
    double K_1 = f(x, y, t);
    double K_2 = f(x + h * ALPHA_2_1, y + h * BETA_21_1 * K_1, t);
    double K_3 = f(x + h * ALPHA_3_1, y + h * (BETA_31_1 * K_1 + BETA_32_1 * K_2), t);

    return y + h * (P_1_1 * K_1 + P_2_1 * K_2 + P_3_1 * K_3);
}

double RungeKuttaScheme2(double x, double y, double h, int t, double(*f)(double, double, int))
{
    double K_1 = f(x, y, t);
    double K_2 = f(x + h * ALPHA_2_2, y + h * BETA_21_2 * K_1, t);
    double K_3 = f(x + h * ALPHA_3_2, y + h * (BETA_31_2 * K_1 + BETA_32_2 * K_2), t);

    return y + h * (P_1_2 * K_1 + P_2_2 * K_2 + P_3_2 * K_3);
}

void PrintTwoSidedRungeKuttaSolution(double h, int t, double(*f)(double, double, int))
{
    int n = static_cast<int>((B - A) / h);
    
    double x = A;

    std::vector<double> values = {Y_0};
    std::vector<double> y_mins = {Y_0};
    std::vector<double> y_maxs = {Y_0};

    std::cout << std::fixed << std::setprecision(6);

    for (int i = 1; i <= n; i++)
    {
        std::vector <double> new_values;
        for (double y : values)
        {
            new_values.push_back(RungeKuttaScheme1(x, y, h, t, f));
            std::cout << "RK S1: " << RungeKuttaScheme1(x, y, h, t, f) << std::endl;
            new_values.push_back(RungeKuttaScheme2(x, y, h, t, f));
            std::cout << "RK S2: " << RungeKuttaScheme2(x, y, h, t, f) << std::endl;

        }
        values = new_values;
        double y_min = *std::min_element(values.begin(), values.end());
        double y_max = *std::max_element(values.begin(), values.end());

        std::cout << "Count of values: " << values.size() << "\n";
        std::cout << "values: ";
        for (int i = 0; i < values.size(); i++)
        {
            std::cout << values[i] << ", ";
        }
        std::cout << std::endl;

        y_mins.push_back(y_min);
        y_maxs.push_back(y_max);      

        x += h;  
    }

    std::cout << "y_mins:" << std::endl;
    for (int i = 0; i <= n; i++)
    {
        std::cout << y_mins[i] << ", ";
    }

    std::cout << std::endl << "y_maxs:" << std::endl;
    for (int i = 0; i <= n; i++)
    {
        std::cout << y_maxs[i] << ", ";
    }
}