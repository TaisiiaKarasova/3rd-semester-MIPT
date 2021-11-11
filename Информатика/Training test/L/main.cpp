#include <iostream>
#include <vector>
#include <cmath>

class star
{
public:

    float x;
    float y;
    int m;

    star(float x, float y, int m): x(x), y(y), m(m) {}

    float distance()
    {
        return sqrt(x*x + y*y);
    }


};

using namespace std;

int main()
{
    vector<star> stars;
    int n;
    cin >> n;
    float x_s, y_s, m_s;
    for (int i = 0; i < n; i++)
    {
        cin >> x_s >> y_s >> m_s;

        if ((sqrt(x_s*x_s + y_s*y_s) <= 100) || (m_s >= 10))
        {
            star object(x_s, y_s, m_s);
            stars.push_back(object);
        }
    }

    for (auto i : stars) cout << i.x <<' '<< i.y << ' ' << i.m <<endl;

}
