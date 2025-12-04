#include <iostream>

using namespace std;
using ll = long long;
const ll MOD = 1'000'000'007LL;

ll n[1'000'010];
ll t[4'000'040];

ll init(int p, int s, int e)
{
	if (s == e) return t[p] = n[s];
	int m = (s + e) >> 1;
	ll a = init((p << 1), s, m);
	ll b = init((p << 1) | 1, m + 1, e);
	return t[p] = (a * b) % MOD;
}

ll query(int p, int ts, int te, int qs, int qe)
{
	if (qs <= ts && te <= qe) return t[p];
	if (te < qs || qe < ts) return 1LL;
	int m = (ts + te) >> 1;
	ll a = query((p << 1), ts, m, qs, qe);
	ll b = query((p << 1) | 1, m + 1, te, qs, qe);
	return (a * b) % MOD;
}

ll update(int p, int s, int e, int i, ll v)
{
	if (i < s || e < i) return t[p];
	if (s == e) return t[p] = v;
	int m = (s + e) >> 1;
	ll a = update((p << 1), s, m, i, v);
	ll b = update((p << 1) | 1, m + 1, e, i, v);
	return t[p] = (a * b) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) cin >> n[i];
	init(1, 1, N);
	for (int i = 1; i <= M + K; ++i)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, N, b, c);
		else cout << query(1, 1, N, b, c) << '\n';
	}

	return 0;
}
