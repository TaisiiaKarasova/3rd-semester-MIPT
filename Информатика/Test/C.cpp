#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class date
{
private:
    int day, month, year;
public:
    date(int day, int month, int year) : day(day), month(month), year(year) {}
    int get_day() const
    {
        return day;
    }
    int get_month() const
    {
        return month;
    }
    int get_year() const
    {
        return year;
    }

    bool operator< (date b) const
    {
        if (year < b.get_year()) return true;
        if (year > b.get_year()) return false;
        if (year == b.get_year())
        {
            if (month < b.get_month()) return true;
            if (month > b.get_month()) return false;
            if (month == b.get_month()) return (day < b.get_day());
        }
    }


    bool operator== (date b) const
    {
        return ((day == b.get_day()) && (month == b.get_month()) && (year == b.get_year()));
    }


};

date string_to_date (string s)
{
    int d, m, y;
    d = (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');
    y = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');

    return date(d, m, y);
}

int main() {
    int number;
    string dat;
    map <date, int> observations;
    vector <int> results;

    int N, M;


    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> dat;
        cin >> number;
        date d = string_to_date(dat);

        if (observations.count(d))
        {
            if (observations[d] < number) observations[d] = number;
        }
        else
            observations.insert(pair<date, int>(d, number));
    }

    cin >> M;
    int maximum = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> dat;
        date data = string_to_date(dat);
        for (auto j: observations)
        {
            if ((j.first < data) || (j.first == data))
            {
                if (j.second > maximum) maximum = j.second;
            }
            else break;
        }
        results.push_back(maximum);
        maximum = 0;
    }

    for (auto i : results)  cout << i << endl;

    return 0;
}