#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ket;
    cin >> ket;

    char stk[31] = {};
    int sav[31] = {};
    int pos = 0, cal = 0;
    bool vld = true;

    for (char c : ket)
    {
        if (c == '(' || c == '[')
        {
            stk[pos] = c;
            sav[pos] += cal;
            cal = 0;
            pos++;
        }
        else
        {
            if (!pos)
            {
                vld = false;
                break;
            }

            pos--;

            if (c == ')')
            {
                if (stk[pos] != '(')
                {
                    vld = false;
                    break;
                }

                if (cal) cal *= 2;
                else cal = 2;
            }

            if (c == ']')
            {
                if (stk[pos] != '[')
                {
                    vld = false;
                    break;
                }

                if (cal) cal *= 3;
                else cal = 3;
            }

            if (pos && sav[pos])
            {
                cal += sav[pos];
                sav[pos] = 0;
            }
        }
    }

    sav[0] += cal;

    if (pos) vld = false;

    if (vld) cout << sav[0];
    else cout << 0;

    return 0;
}
