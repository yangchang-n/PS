#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

#include <iostream>

char stk[51];
int pos;

int main()
{
    fastIO;

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc)
    {
        string str;
        cin >> str;

        pos = 0;
        bool vld = true;

        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == '(') stk[pos++] = str[i];
            else if (str[i] == ')')
            {
                if (!pos || stk[pos - 1] == ')')
                {
                    vld = false;
                    break;
                }
                else pos--;
            }
        }

        if (pos) vld = false;

        if (vld) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
