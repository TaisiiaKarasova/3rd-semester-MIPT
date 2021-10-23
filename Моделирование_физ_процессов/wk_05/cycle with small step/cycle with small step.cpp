#include <iostream>
#include <cmatath>

int main()
{
    float t = 0;
    float * dt = new float[10];
    dt[0] = 0.5;
    for (int i = 1; i < 10; i++) dt[i] = dt[i - 1] / 2;
    int c = 0;

    for (int i = 0; i < 10; i++)
    {
        t = 0;
        c = 0;
        while (t < 100000 * dt[i])
        {
            t += dt[i];
            c++;
        }

        std::cout << 100000 * dt[i]  << " dt = " << dt[i] << " number of steps = " << c << " difference = " << c - 100000 <<  std::endl;

    }
}


