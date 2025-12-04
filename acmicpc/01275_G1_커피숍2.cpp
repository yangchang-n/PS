#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll n[100'010];
ll t[400'040];

ll init(int p, int s, int e)
{
	if (s == e) return t[p] = n[s];
	int m = (s + e) >> 1;
	ll a = init((p << 1), s, m);
	ll b = init((p << 1) | 1, m + 1, e);
	return t[p] = a + b;
}

ll query(int p, int s, int e, int qs, int qe)
{
	if (qs <= s && e <= qe) return t[p];
	if (e < qs || qe < s) return 0LL;
	int m = (s + e) >> 1;
	ll a = query((p << 1), s, m, qs, qe);
	ll b = query((p << 1) | 1, m + 1, e, qs, qe);
	return a + b;
}

ll update(int p, int s, int e, int i, ll v)
{
	if (i < s || e < i) return t[p];
	if (s == e) return t[p] = v;
	int m = (s + e) >> 1;
	ll a = update((p << 1), s, m, i, v);
	ll b = update((p << 1) | 1, m + 1, e, i, v);
	return t[p] = a + b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) cin >> n[i];
	init(1, 1, N);
	for (int i = 1; i <= Q; ++i)
	{
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << query(1, 1, N, x, y) << '\n';
		update(1, 1, N, a, b);
	}

	return 0;
}
