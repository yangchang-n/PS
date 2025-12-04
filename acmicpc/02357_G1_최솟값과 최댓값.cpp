#include <iostream>
#include <algorithm>
#include <array>

using namespace std;
using ai2 = array<int, 2>;

int n[100'010];
ai2 t[400'040];

ai2 init(int p, int s, int e)
{
	if (s == e) return t[p] = { n[s], n[s] };
	int m = (s + e) >> 1;
	ai2 a = init((p << 1), s, m);
	ai2 b = init((p << 1) | 1, m + 1, e);
	return t[p] = { min(a[0], b[0]), max(a[1], b[1]) };
}

ai2 query(int p, int ts, int te, int qs, int qe)
{
	if (qs <= ts && te <= qe) return t[p];
	if (te < qs || qe < ts) return { 1'000'000'010, 0 };
	int m = (ts + te) >> 1;
	ai2 a = query((p << 1), ts, m, qs, qe);
	ai2 b = query((p << 1) | 1, m + 1, te, qs, qe);
	return { min(a[0], b[0]), max(a[1], b[1]) };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, a, b;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) cin >> n[i];
	init(1, 1, N);
	for (int i = 1; i <= M; ++i)
	{
		cin >> a >> b;
		ai2 ans = query(1, 1, N, a, b);
		cout << ans[0] << ' ' << ans[1] << '\n';
	}

	return 0;
}
