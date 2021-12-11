#include <iostream>
#include <cmath>
#include <array>
#include <vector>

int main()
{
    float R = 6371 * pow(10, 6);

    std::array<double,3000> ae;
    ae[0] = R;

    std::array<double,3000> be;
    be[0] = 0.0;

    std::vector<double> Te;

    float dt = 0.01;

    for (int i = 1; i < 3000; i++)
    {
        ae[i] = ae[i - 1] + dt * be[i - 1];
        be[i] = be[i - 1] - dt * sin(ae[i - 1]);
        float bi2 = be[i]; 
        float bi1 = be[i - 1]; 
        if (bi2 * bi1 <= 0)
        {
            Te.push_back(dt * i);
        }
    }

    std::cout << "Period calculated by Euler method = " << Te[2] - Te[0] << std::endl;


    std::array<double, 3000> ah;
    ah[0] = R;

    std::array<double, 3000> bh;
    bh[0] = 0.0;

    std::vector<double> Th;

    double a1, b1;

    for (int i = 1; i < 3000; i++)
    {
        a1 = ah[i - 1] + dt * bh[i - 1];
        b1 = bh[i - 1] - dt * sin(ah[i - 1]);

        ah[i] = ah[i - 1] + dt * (bh[i - 1] + b1) / 2;
        bh[i] = bh[i - 1] - dt * (sin(ah[i - 1]) + sin(a1)) / 2;
        float bi2 = bh[i];
        float bi1 = bh[i - 1]; 
        if (bi1 * bi2 <= 0)
        {
            Th.push_back(dt * i);
        }
    }

    std::cout << "Period calculated by Heun method = " << Th[2] - Th[0] << std::endl;

}
