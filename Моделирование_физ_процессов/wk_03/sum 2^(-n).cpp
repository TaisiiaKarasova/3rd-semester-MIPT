#include <iostream>
#include <iomanip>
#include <float.h>
int nearlyEqual(float a, float b, float eps)
{
   float absA = fabs(a);
   float absB = fabs(b);
   float diff = fabs(a - b);
    
        if (a == b)
        {
           return true;
        }
        else if (a == 0 || b == 0 || diff < FLT_MIN)
        {
            return (diff < (eps* FLT_MIN));
        }
        else
        {
            return (diff / (absA + absB) < eps);
        }
}



int main()
{
    float res = 0, previous_res = 0;
    int denominator;

    for (int i = 1; i <= 100; i++)
    {
        denominator = 1 << i;
        res += 1.0 / denominator;
        std::cout << i << ' ';
        if (nearlyEqual(res, previous_res, 0.0000001)) break;
        previous_res = res;
    }

    std::cout << res << std::endl;

    
}
