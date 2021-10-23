#include <iostream>
#include <cmath>
#include <fstream>

int main()
{
    double R = 6371 * pow(10, 6);

    std::ofstream E("e double.txt");


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
        for (int j = 0; j < number_of_iterations; j++)
        {
            previous_a = a;
            previous_b = b;
            a = previous_a + previous_b * dt;
            b = previous_b - previous_a * dt;
        }

        E << (a * a) / 2 + (b * b) / 2 << std::endl;

    }
}

