#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
    std::ofstream aefout("Ae.bin", std::ios::binary);
    std::ofstream befout("Be.bin", std::ios::binary);

    std::ofstream ahfout("Ah.bin", std::ios::binary);
    std::ofstream bhfout("Bh.bin", std::ios::binary);

    std::ofstream aevfout("Aev.bin", std::ios::binary);
    std::ofstream bevfout("Bev.bin", std::ios::binary);

    std::ofstream ahvfout("Ahv.bin", std::ios::binary);
    std::ofstream bhvfout("Bhv.bin", std::ios::binary);

    double R = 6371000000;
    double a = R;
    double previous_a = R;
    double b = 0.0;
    double previous_b = 0.0;
    double dt = 0.01;


    for (int i = 0; i < 3000; i++)
    {
        aefout.write((char*)&a, sizeof(a));
        befout.write((char*)&b, sizeof(b));
        a = previous_a + dt * previous_b;
        b = previous_b - dt * sin(previous_a);
        previous_a = a;
        previous_b = b;
    }
    aefout.close();
    befout.close();

    a = R;
    previous_a = R;
    b = 0.0;
    previous_b = 0.0;
    double a1, b1;

    for (int i = 0; i < 3000; i++)
    {
        ahfout.write((char*)&a, sizeof(a));
        bhfout.write((char*)&b, sizeof(b));
        a1 = previous_a + dt * previous_b;
        b1 = previous_b - dt * sin(previous_a);
        a = previous_a + dt * (previous_b + b1) / 2;
        b = previous_b - dt * (sin(previous_a) + sin(a1)) / 2;
        previous_a = a;
        previous_b = b;
    }
    ahfout.close();
    bhfout.close();

    a = R;
    previous_a = R;
    b = 0.4;
    previous_b = 0.4;

    for (int i = 0; i < 2000; i++)
    {
        aevfout.write((char*)&a, sizeof(a));
        bevfout.write((char*)&b, sizeof(b));
        a = previous_a + dt * previous_b;
        b = previous_b - dt * sin(previous_a);
        previous_a = a;
        previous_b = b;
    }
    aevfout.close();
    bevfout.close();

    a = R;
    previous_a = R;
    b = 0.4;
    previous_b = 0.4;

    for (int i = 0; i < 2000; i++)
    {
        ahvfout.write((char*)&a, sizeof(a));
        bhvfout.write((char*)&b, sizeof(b));
        a1 = previous_a + dt * previous_b;
        b1 = previous_b - dt * sin(previous_a);
        a = previous_a + dt * (previous_b + b1) / 2;
        b = previous_b - dt * (sin(previous_a) + sin(a1)) / 2;
        previous_a = a;
        previous_b = b;
    }
    ahvfout.close();
    bhvfout.close();
}
