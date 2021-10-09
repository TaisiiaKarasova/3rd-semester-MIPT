#include <iostream>
#include <cmath>
#include <fstream>

int main()
{
    float R = 6371 * pow(10, 6);

    std::ofstream A1("a1.txt");
    std::ofstream B1("b1.txt");

    std::ofstream A2("a2.txt");
    std::ofstream B2("b2.txt");

    
    float dt1 = 0.1;
    float dt2 = 0.01;

    float a = R;
    float previous_a = R;
    float b = 0.0;
    float previous_b = 0.0;


    for (int i = 0; i < 10; i++)
    {
        A1 << a << std::endl;
        B1 << b << std::endl;
        previous_a = a;
        previous_b = b;
        a = previous_a + previous_b * dt1;
        b = previous_b - previous_a * dt1;
    }


    a = R;
    previous_a = R;
    b = 0.0;
    previous_b = 0.0;

    for (int i = 0; i < 100; i++)
    {
        A2 << a << std::endl;
        B2 << b << std::endl;
        previous_a = a;
        previous_b = b;
        a = previous_a + previous_b * dt2;
        b = previous_b - previous_a * dt2;
    }
}

