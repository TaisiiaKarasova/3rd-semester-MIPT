#include<iostream>
#include <cmath>
#include <list>
using namespace std;



string operator_or_number (string s)
{
    if (s.length() != 1) return "number";
    else if (s[0] == '+' || s[0] == '*' || s[0] == '/' || s[0] == '-') return "operator";
    else return "number";

}

int StrToInt(string s)
{
    int l, M;
    l = s.length();
    M = 0;
    if (s[0] == '-')
    {
        for (int i = 1; i < l; i++)
        {
            M += (s[i] - '0') * pow(10, l - i - 1);
        }
        return -M;
    }
    else
    {
        for (int i = 0; i < l; i++)
        {
            M += (s[i] - '0') * pow(10, l - i - 1);
        }
        return M;
    }
}

int main()
{

    list<int> ls;
    string Polish_sign = "nothing";



   while (Polish_sign != "=")
    {
        cin >> Polish_sign;
        if (Polish_sign != "=")
        {
         if (operator_or_number(Polish_sign) == "operator")
            {
                int last_number = ls.front();
                ls.pop_front();
                int pre_last_number = ls.front();
                ls.pop_front();
                if (Polish_sign == "+") ls.push_front(pre_last_number + last_number);
                if (Polish_sign == "*") ls.push_front(pre_last_number * last_number);
                if (Polish_sign == "/") ls.push_front(pre_last_number / last_number);
                if (Polish_sign == "-") ls.push_front(pre_last_number - last_number);
            }
                else ls.push_front(StrToInt(Polish_sign));

        }
    }

    cout << ls.front() <<'\n';

    return 0;
}
