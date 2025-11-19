#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

ll mod_pow(ll a, ll e)
{
	ll r = 1;
	a %= MOD;
	while (e)
	{
		if (e & 1) r = (r * a) % MOD;
		a = (a * a) % MOD;
		e >>= 1;
	}
	return r;
}

ll get_mul(int n, int pn, int i, int pi)
{
	int gap = n - pn - 1;
	int cnt = i - pi - 1;
	if (cnt <= 0) return 1;
	if (cnt * 2 > gap) cnt = gap - cnt;

	ll num = 1;
	ll den = 1;
	for (int k = 1; k <= cnt; ++k)
	{
		num = (num * (ll)(gap - k + 1)) % MOD;
		den = (den * (ll)k) % MOD;
	}

	ll den_inv = mod_pow(den, MOD - 2);

	return (num * den_inv) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num[110] = {};
	int N, K, t, p;
	cin >> N >> K;

	int s = 0;
	int e = N - 1;
	int m = (s + e) / 2;

	cin >> p;
	num[m] = p;
	for (int i = 2; i <= K; ++i)
	{
		cin >> t;
		if (t < p) e = m - 1;
		else s = m + 1;
		m = (s + e) / 2;
		num[m] = t;
		p = t;
	}

	ll ans = 1;
	ll mul = 1;
	int pn = 0;
	int pi = -1;
	for (int i = 0; i < N; ++i)
	{
		if (!num[i]) continue;
		mul = get_mul(num[i], pn, i, pi);
		ans = (ans * mul) % MOD;
		pn = num[i];
		pi = i;
	}
	mul = get_mul(101, pn, N, pi);
	ans = (ans * mul) % MOD;

	cout << ans;

	return 0;
}
