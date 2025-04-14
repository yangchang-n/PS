#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

#include <iostream>

char stk[50'001];
int pos;

int main()
{
    fastIO;

    int N, ans = 0;
    cin >> N;

    for (int tc = 1; tc <= N; ++tc)
    {
        string str;
        cin >> str;

        pos = 0;
        bool vld = true;
        for (int i = 0; i < str.size(); ++i)
        {
            char cur = str[i];

            if (!pos) stk[pos++] = cur;
            else
            {
                if (cur == stk[pos - 1]) pos--;
                else stk[pos++] = cur;
            }

            if (pos > 50'000)
            {
                vld = false;
                break;
            }
        }

        if (pos) vld = false;
        if (vld) ans++;
    }

    cout << ans;
    
    return 0;
}
