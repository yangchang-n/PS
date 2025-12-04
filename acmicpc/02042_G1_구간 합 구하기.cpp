#include <iostream>

using namespace std;
using ll = long long;

ll n[1'000'010];
ll t[4'000'040];

ll init(ll* t, int node, int s, int e)
{
	if (s == e) return t[node] = n[s];
	int m = (s + e) >> 1;
	ll a = init(t, (node << 1), s, m);
	ll b = init(t, (node << 1) | 1, m + 1, e);
	return t[node] = a + b;
}

ll query(ll* t, int node, int ts, int te, int qs, int qe)
{
	if (qs <= ts && te <= qe) return t[node];
	if (te < qs || qe < ts) return 0LL;
	int tm = (ts + te) >> 1;
	ll a = query(t, (node << 1), ts, tm, qs, qe);
	ll b = query(t, (node << 1) | 1, tm + 1, te, qs, qe);
	return a + b;
}

ll update(ll* t, int node, int s, int e, int i, ll v)
{
	if (i < s || e < i) return t[node];
	if (s == e) return t[node] = v;
	int m = (s + e) >> 1;
	ll a = update(t, (node << 1), s, m, i, v);
	ll b = update(t, (node << 1) | 1, m + 1, e, i, v);
	return t[node] = a + b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K, a, b; ll c;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) cin >> n[i];
	init(t, 1, 1, N);
	for (int i = 1; i <= M + K; ++i)
	{
		cin >> a >> b >> c;
		if (a == 1) update(t, 1, 1, N, b, c);
		else cout << query(t, 1, 1, N, b, c) << '\n';
	}

	return 0;
}
