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
    set<string, greater <string>> words;

    string word;

    for(int i = 0; i < n; i++)
    {
        cin >> word;
        from_big_to_small(word);
        words.insert(word);
    }

    for (auto i: words) cout << i << ' ';

    cout<<endl;
    return 0;
}
