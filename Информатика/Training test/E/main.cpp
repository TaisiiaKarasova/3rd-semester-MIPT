#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a;
    vector<int> my_stack{};
    cin >> a;
    while(a != 0)
    {
        if(a > 0)
            my_stack.push_back(a);
        else
        {
            if(!my_stack.empty())
            {
                if(abs(a) < abs(my_stack.back()))
                    my_stack.back() += a;
                else
                {
                    if(abs(a) >= abs(my_stack.back()))
                        my_stack.pop_back();
                }
            }
        }
        cin >> a;
    }
    cout << my_stack.size() << " ";
    if(my_stack.size() == 0)
        cout << -1 << endl;
    else
        cout << my_stack.back() << endl;

    return 0;
}
