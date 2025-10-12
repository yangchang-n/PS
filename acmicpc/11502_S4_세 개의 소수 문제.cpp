#include <iostream>

using namespace std;

bool isPrime[1010];
int prime[100] = { 2 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    isPrime[2] = 1;
    for (int i = 3; i < 1010; i += 2) isPrime[i] = 1;
    for (int i = 3; i * i < 1010; i += 2)
    {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < 1010; j += 2 * i) isPrime[j] = 0;
    }

    int pos = 1;
    for (int i = 3; i < 1010; i += 2)
    {
        if (!isPrime[i]) continue;
        prime[pos++] = i;
    }

    int T, K;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        cin >> K;
        bool possible = false;

        for (int a : prime)
        {
            if (possible) break;
            if (!a || a >= K) break;

            for (int b : prime)
            {
                if (possible) break;
                if (!b || b >= K) break;

                for (int c : prime)
                {
                    if (possible) break;
                    if (!c || c >= K) break;

                    if (a + b + c == K)
                    {
                        possible = true;
                        cout << a << ' ' << b << ' ' << c << '\n';
                    }
                }
            }
        }

        if (!possible) cout << "0\n";
    }

    return 0;
}
