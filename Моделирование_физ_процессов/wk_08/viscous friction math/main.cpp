#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

double str_to_double (std::string s)
{
    double res = 0;
    int len = s.length();
    res = s[0] - '0';
    std::cout << s[0] - '0'<<std::endl;
    for (int i = 2; i < len; i++)
    {
        std::cout << s[i] - '0'<<std::endl;
        res+= (s[i] - '0') * pow(10, 1 - i);
    }
    return res;

}

int main(int argc, char** argv)
{
    if (argc != 6) return 1;

    std::ofstream x_euler_fout("x_euler.bin", std::ios::binary);
    std::ofstream v_euler_fout("v_euler.bin", std::ios::binary);

    std::ofstream x_heun_fout("x_heun.bin", std::ios::binary);
    std::ofstream v_heun_fout("v_heun.bin", std::ios::binary);

    double A, d, Q;
    double x = str_to_double(argv[3]);
    double previous_x = x;
    double v = str_to_double(argv[4]);
    double previous_v = v;
    double dt = str_to_double(argv[5]);
    double beta = str_to_double(argv[2]);
    double omega = str_to_double(argv[1]);

    std::cout << " omega = " << omega << " beta = " << beta << ' ' << " x = " << x << ' ' << " v = " << v << " dt = " << dt << std::endl;

    for (int i = 0; i < (int)10.0/dt; i++)
    {
        x_euler_fout.write((char*)&x, sizeof(x));
        v_euler_fout.write((char*)&v, sizeof(v));
        x = previous_x + dt * previous_v;
        v = previous_v - dt * (omega * omega * previous_x + beta * previous_v);
        if (previous_v * v <= 0)
        {
            A = x;
        }
        previous_x = x;
        previous_v = v;
    }
    x_euler_fout.close();
    v_euler_fout.close();
    d = log(1 / A);
    Q = 3.1415926535 / d;
    std::cout << "Quality factor calculated by Euler method = " << Q << std::endl;


    x = str_to_double(argv[3]);
    previous_x = x;
    v = str_to_double(argv[4]);
    previous_v = v;
    double x1, v1;

    std::cout << " number of iterations = " << (int)10.0/dt;

    for (int i = 0; i < (int)10.0/dt; i++)
    {
        x_heun_fout.write((char*)&x, sizeof(x));
        v_heun_fout.write((char*)&v, sizeof(v));
        x1 = previous_x + dt * previous_v;
        v1 = previous_v - dt * (omega * omega * previous_x + beta * previous_v);
        x = previous_x + dt * (previous_v + v1) / 2;
        v = previous_v - dt * (omega * omega * previous_x + beta * previous_v + omega * omega * x1 + beta * v1) / 2;
        if (previous_v * v <= 0)
        {
            A = x;
        }
        previous_x = x;
        previous_v = v;
    }
    x_heun_fout.close();
    v_heun_fout.close();
    d = log(1 / A);
    Q = 3.1415926535 / d;

    std::cout << "Quality factor calculated by Heun method = " << Q << std::endl;


    return 0;
}