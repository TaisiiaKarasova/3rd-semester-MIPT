#include <iostream>
#include <cmath>
#include <fstream>

int main()
{
    double R = 6371 * pow(10, 6);

    std::ofstream E("e Kahan.txt");


    double* dT = new double[15];
    dT[0] = 0.1;

    for (int i = 1; i < 15; i++)
    {
        dT[i] = dT[i - 1] / 10.0;
    }


    double a = R;
    double previous_a = R;
    double b = 0.0;
    double previous_b = 0.0;

    for (int i = 0; i < 15; i++)
    {
        a = R;
        previous_a = R;
        b = 0.0;
        previous_b = 0.0;
        double dt = dT[i];
        double number = 1.0 / dt;
        int number_of_iterations = (int)number;
        double error_sum_a = 0.0;
        double error_sum_b = 0.0;
        double t_a, t_b, y_a, y_b;
        for (int j = 0; j < number_of_iterations; j++)
        {
            y_a = previous_b * dt - error_sum_a;
            t_a = previous_a + y_a;
            error_sum_a = t_a - previous_a - y_a;
            a = t_a;

            y_b = - previous_a * dt - error_sum_b;
            t_b = previous_b + y_b;
            error_sum_b = t_b - previous_b - y_b;
            b = t_b;
            
            previous_a = a;
            previous_b = b;
        }

        E << (a * a) / 2 + (b * b) / 2 << std::endl;
    }


}
