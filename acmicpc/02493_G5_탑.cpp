#include <iostream>

using namespace std;

int tower[500'001][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, cur;
    cin >> N;

    tower[0][0] = 100'000'001;
    tower[0][1] = 0;
    int pos = 1;

    for (int i = 1; i <= N; ++i)
    {
        cin >> cur;

        while (true)
        {
            if (tower[pos - 1][0] > cur) break;
            pos--;
        }

        cout << tower[pos - 1][1] << ' ';

        tower[pos][0] = cur;
        tower[pos][1] = i;
        pos++;
    }

    return 0;
}
