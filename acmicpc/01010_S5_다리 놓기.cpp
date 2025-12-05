#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T, N, M;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        ll r = M - N;
        if (r > M / 2) r = N;
        ll ans = 1;
        for (ll i = M; i > M - r; --i) ans *= i;
        for (ll i = 1; i <= r; ++i) ans /= i;
        cout << ans << '\n';
    }

    return 0;
}
