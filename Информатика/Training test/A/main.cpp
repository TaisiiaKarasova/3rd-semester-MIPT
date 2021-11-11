#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> numbers;
    set<vector<int>> rezults;

    int number;

    for (int i = 0; i < N; i++)
    {
        cin >> number;
        numbers.push_back(number);
    }

    int sum;
    cin >> sum;

    sort(numbers.begin(), numbers.end());


    for (int a = 0; a < N - 3; a++)
        for (int b = a + 1; b < N - 2; b++)
            for (int c = b + 1; c < N - 1; c++)
                for (int d = c + 1; d < N; d++)
                    if (numbers[a] + numbers[b] + numbers[c] + numbers[d] == sum)
                        rezults.insert(vector<int>({numbers[a],numbers[b],numbers[c],numbers[d]}));

    for (auto& i: rezults)
        for (int j: i) cout << j << ' ';
    cout << endl;


}
