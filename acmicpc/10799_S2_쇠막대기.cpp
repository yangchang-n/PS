#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string bars;
    cin >> bars;

    int pos = 0, ans = 0;
    char pre = ')';

    for (char c : bars)
    {
        if (c == '(')
        {
            if (pre == '(') pos++;
        }
        else
        {
            if (pre == '(') ans += pos;
            else
            {
                ans++;
                pos--;
            }
        }

        pre = c;
    }

    cout << ans;
    
    return 0;
}
