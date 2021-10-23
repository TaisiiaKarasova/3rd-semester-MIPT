#include <iostream>
#include <cmath>
#include <fstream>

int main()
{
    float R = 6371 * pow(10, 6);

    std::ofstream AE("ae.txt");
    std::ofstream BE("be.txt");

    std::ofstream AC("ac.txt");
    std::ofstream BC("bc.txt");

   float dt = 0.01;
   float a = R;
   float previous_a = R;
   float b = 0.0;
   float previous_b = 0.0;

    for (int i = 0; i < 10000; i++)
    {
        AE << a << std::endl;
        BE << b << std::endl;
        previous_a = a;
        previous_b = b;
        a = previous_a + previous_b * dt;
        b = previous_b - previous_a * dt;
    }

    a = R;
    previous_a = R;
    b = 0.0;
    previous_b = 0.0;
    float a1, b1;

    for (int i = 0; i < 10000; i++)
    {
        AC << a << std::endl;
        BC << b << std::endl;
        previous_a = a;
        previous_b = b;
        a1 = previous_a + previous_b * dt;
        b1 = previous_b - previous_a * dt;

        a = previous_a + dt * (previous_b + b1) / 2;
        b = previous_b - dt * (previous_a + a1) / 2;
    }
}
