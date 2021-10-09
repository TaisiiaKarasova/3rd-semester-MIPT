#include <iostream>
#include <cmath>
#include <fstream>

int main()
{
    float R = 6371 * pow(10, 6);

    std::ofstream E("e.txt");


    float* dT = new float[8];
    dT[0] = 0.1;

    for (int i = 1; i < 8; i++)
    {
        dT[i] = dT[i - 1] / 10.0;
    }


    float a = R;
    float previous_a = R;
    float b = 0.0;
    float previous_b = 0.0;

    for (int i = 0; i < 8; i++)
    {
        a = R;
        previous_a = R;
        b = 0.0;
        previous_b = 0.0;
        float dt = dT[i];
        float number = 1.0 / dt;
        int number_of_iterations = (int)number;
        for (int i = 0; i < number_of_iterations; i++)
        {
            previous_a = a;
            previous_b = b;
            a = previous_a + previous_b * dt;
            b = previous_b - previous_a * dt;
        }

        E << (a * a) / 2 + (b * b) / 2 << std::endl;

    }
}

