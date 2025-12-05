#include <iostream>

using namespace std;
using ll = long long;

ll tb[35][20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int n = 1; n < 30; ++n)
    {
        tb[n][0] = 1;
        tb[n][1] = n;
        for (int r = 2; r <= n / 2; ++r)
        {
            tb[n][r] = tb[n][r - 1] * (n - r + 1) / r;
        }
    }

    int T, N, M;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        if (N > M / 2) N = M - N;
        cout << tb[M][N] << '\n';
    }

    return 0;
}
