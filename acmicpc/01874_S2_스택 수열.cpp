#include <iostream>
#include <vector>

using namespace std;

int stk[100001];
vector<char> opt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int tmp = 0, num, pre = n + 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;

        if (num > tmp)
        {
            for (int j = tmp; j < num; ++j)
            {
                stk[j + 1] = 1;
                opt.push_back('+');
            }

            tmp = num;
        }
        else
        {
            for (int j = pre; j > num; --j)
            {
                if (stk[j])
                {
                    cout << "NO";
                    return 0;
                }
            }
        }

        stk[num] = 0;
        opt.push_back('-');

        pre = num;
    }

    for (int i = 0; i < n * 2; ++i) cout << opt[i] << '\n';

    return 0;
}
