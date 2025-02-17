#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case)
    {
        char str[100001];
        cin >> str;

        int cnt = 0, l = 0, r = strlen(str) - 1;

        while (l < r)
        {
            if (str[l] == str[r])
            {
                l++;
                r--;
            }
            else if (str[l] == 'x')
            {
                l++;
                cnt++;
            }
            else if (str[r] == 'x')
            {
                r--;
                cnt++;
            }
            else
            {
                cnt = -1;
                break;
            }
        }

        cout << cnt << '\n';
    }
    
    return 0;
}
