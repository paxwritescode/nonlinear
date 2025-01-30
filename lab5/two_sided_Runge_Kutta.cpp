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

void PrintTwoSidedRungeKuttaSolution(double h, int t, double(*f)(double, double, int), std::ofstream& outFile)
{
    int n = static_cast<int>((B - A) / h);
    
    double x = A;

    std::vector<double> values = {Y_0};
    std::vector<double> y_mins = {Y_0};
    std::vector<double> y_maxs = {Y_0};

    double y_min = Y_0;
    double y_max = Y_0;

    std::cout << std::fixed << std::setprecision(6);

    for (int i = 1; i <= n; i++)
    {
        double y1_min = RungeKuttaScheme1(x, y_min, h, t, f);
        double y1_max = RungeKuttaScheme1(x, y_max, h, t, f);

        double y2_min = RungeKuttaScheme2(x, y_min, h, t, f);
        double y2_max = RungeKuttaScheme2(x, y_max, h, t, f);

        y_min = std::min({y1_min, y1_max, y2_min, y2_max});
        y_max = std::max({y1_min, y1_max, y2_min, y2_max});

        y_mins.push_back(y_min);
        y_maxs.push_back(y_max);   

        x += h;        
    }



    outFile << "y_mins:" << std::endl;
    for (int i = 0; i <= n; i++)
    {
        outFile << y_mins[i] << ", ";
    }

    outFile << std::endl << "y_maxs:" << std::endl;
    for (int i = 0; i <= n; i++)
    {
        outFile << y_maxs[i] << ", ";
    }    

    outFile << std::endl << "difference:" << std::endl;
    for (int i = 0; i <= n; i++)
    {
        outFile << y_maxs[i] - y_mins[i] << ", ";
    }    
}