#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    float vit_d, acat, anti_tg, neural_activity, mch, maxx, minn, dif;
    unordered_map<int, vector<float>> data;
    multimap<float, int> dif_id;
    vector<float> difs;
    vector<int> minimals;
    bool detected = false;

    int time_stamp, id;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> time_stamp >> id >> vit_d >> acat >> anti_tg >> neural_activity >> mch;
        data[id].push_back(neural_activity);
    }

    for (auto i : data)
    {
        if (i.second.size() > 1)
        {
            detected = true;
            maxx = *max_element(i.second.begin(), i.second.end());
            minn = *min_element(i.second.begin(), i.second.end());
            dif = maxx - minn;
            dif_id.insert({dif, i.first});
            difs.push_back(dif);
        }

    }




    if (detected)
    {
        multimap<float, int>::iterator it;
        it = dif_id.begin();
        if (dif_id.size() == 1) cout << (*it).second << ' ';
        if (dif_id.size() == 2)
        {
            minimals.push_back((*it).second);
            it++;
            minimals.push_back((*it).second);
            sort(minimals.begin(), minimals.end());
            for (auto i : minimals) cout << i << ' ';
            cout << endl;
        }
        if (difs.size() > 2)
        {
        minimals.push_back((*it).second);
        it++;
        minimals.push_back((*it).second);
        it++;
        minimals.push_back((*it).second);
        sort(minimals.begin(), minimals.end());
            for (auto i : minimals) cout << i << ' ';
            cout << endl;
        }

    }
    else cout << -1 << endl;



}
