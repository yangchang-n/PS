#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> stk;
vector<char> opt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int tmp = 0, num;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;

        if (num > tmp)
        {
            for (int j = tmp; j < num; ++j)
            {
                stk.push(j + 1);
                opt.push_back('+');
            }

            tmp = num;
        }
        else
        {
            if (stk.top() != num)
            {
                cout << "NO";
                return 0;
            }
        }

        stk.pop();
        opt.push_back('-');
    }

    for (char c : opt) cout << c << '\n';

    return 0;
}
