#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int> people;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        people.push_back(i);
    }

    int starter_number = 0;

    for (int j = 0; j < n; j++)
    {
        if (starter_number + m < people.size())
        {
            if (people.size() <= 3) cout << people[starter_number - 1 + m] + 1 << ' ';
            people.erase(people.begin() + starter_number - 1 + m);
            starter_number = starter_number + m - 1;
        }
        else
        {
            int k = (starter_number + m - 1) % people.size();
            if (people.size() <= 3) cout << people[(starter_number + m - 1) % people.size()] + 1<< ' ';
            people.erase(people.begin() + (starter_number + m - 1) % people.size());
            starter_number = k;
        }

    }

        cout << endl;
}
