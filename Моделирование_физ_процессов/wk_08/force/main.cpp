#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

int main(int argc, char** argv)
{
    if (argc != 9) return 1;

    std::ofstream x_euler_fout("x_euler.bin", std::ios::binary);
    std::ofstream v_euler_fout("v_euler.bin", std::ios::binary);

    std::ofstream x_heun_fout("x_heun.bin", std::ios::binary);
    std::ofstream v_heun_fout("v_heun.bin", std::ios::binary);

    std::ofstream frequency("frequency.bin", std::ios::binary);
    std::ofstream amplitude("amplitude.bin", std::ios::binary);


    double A;
    double x = std::stod(argv[3]);
    double previous_x = x;
    double v = std::stod(argv[4]);
    double previous_v = v;
    double dt = std::stod(argv[7]);
    double time = std::stod(argv[8]);
    double beta = std::stod(argv[2]);
    double omega = std::stod(argv[1]);
    double force_omega = std::stod(argv[6]);
    double force = std::stod(argv[5]);
    double freq;
    double previous_time = 0;
    double period;

    


    for (int i = 0; i < (int)(time/dt); i++)
    {
        x_euler_fout.write((char*)&x, sizeof(x));
        v_euler_fout.write((char*)&v, sizeof(v));
        x = previous_x + dt * previous_v;
        v = previous_v - dt * (omega * omega * previous_x + beta * previous_v - force * cos(force_omega * dt * i));

        if (previous_v * v <= 0)
        {
            freq = 1 / (2 * (dt * i - previous_time));
            previous_time = dt * i;
            A = abs(x);
        }
        previous_x = x;
        previous_v = v;
    }
    frequency.write((char*)&freq, sizeof(freq));
    amplitude.write((char*)&A, sizeof(A));
    frequency.close();
    amplitude.close();
    x_euler_fout.close();
    v_euler_fout.close();



    x = std::stod(argv[3]);
    previous_x = x;
    v = std::stod(argv[4]);
    previous_v = v;
    double x1, v1;


    for (int i = 0; i < (int)(time/dt); i++)
    {
        x_heun_fout.write((char*)&x, sizeof(x));
        v_heun_fout.write((char*)&v, sizeof(v));
        x1 = previous_x + dt * previous_v;
        v1 = previous_v - dt * (omega * omega * previous_x + beta * previous_v - force * cos(force_omega * dt * i));
        x = previous_x + dt * (previous_v + v1) / 2;
        v = previous_v - dt * (omega * omega * previous_x + beta * previous_v + omega * omega * x1 + beta * v1) / 2 + dt * force * cos(force_omega * dt * i);
        if (previous_v * v <= 0)
        {
            freq = 1 / (2 * (dt * i - previous_time));
            previous_time = dt * i;
            A = abs(x);
        }
        previous_x = x;
        previous_v = v;
    }
    frequency.write((char*)&freq, sizeof(freq));
    amplitude.write((char*)&A, sizeof(A));
    frequency.close();
    amplitude.close();
    x_euler_fout.close();
    v_euler_fout.close();


    return 0;
}
