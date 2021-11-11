#include <iostream>
#include <map>

using namespace std;
int main()
{
    int n, element, counti = 0;
    cin >> n;
    map<int,int> uniquee;

    for(int i = 0; i < n; i++)
    {
        cin >> element;
        uniquee[element]++;
    }
    cout << uniquee.size() << endl;

    return 0;
}
