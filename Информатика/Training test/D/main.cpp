#include <iostream>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;


void from_big_to_small(string & word)
{
    for(int i = 0; i < word.size(); i++)
        word[i] = tolower(word[i]);
}


int main(){
    int n;
    cin >> n;
    multiset<string> words;
    string word;

    string most_popular;
    int number, maxx;

    maxx = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> word;
        from_big_to_small(word);
        words.insert(word);

        number = words.count(word);
        if (number > maxx)
        {
            maxx = number;
            most_popular = word;
        }
    }
    cout << most_popular << ' '<< maxx << endl;
    return 0;
}
