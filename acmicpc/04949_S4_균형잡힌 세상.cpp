#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

#include <iostream>

char str[101];
char stk[51];
int pos;

int main()
{
    fastIO;

    while (true)
    {
        cin.getline(str, 101);
        if (str[0] == '.') break;

        pos = 0;
        bool vld = true;

        int i = 0;
        while (true)
        {
            if (str[i] == '.') break;

            if (str[i] == '(' || str[i] == '[') stk[pos++] = str[i];
            else if (str[i] == ')')
            {
                if (!pos || stk[pos - 1] != '(')
                {
                    vld = false;
                    break;
                }
                else pos--;
            }
            else if (str[i] == ']')
            {
                if (!pos || stk[pos - 1] != '[')
                {
                    vld = false;
                    break;
                }
                else pos--;
            }

            i++;
        }

        if (pos) vld = false;

        if (vld) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
