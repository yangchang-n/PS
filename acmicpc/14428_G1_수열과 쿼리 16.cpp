#include <iostream>
#include <algorithm>

using namespace std;

int n[100'010];
int t[400'040];

int init(int p, int s, int e)
{
	if (s == e) return t[p] = s;
	int m = (s + e) >> 1;
	int a = init((p << 1), s, m);
	int b = init((p << 1) | 1, m + 1, e);
	return t[p] = (n[a] <= n[b] ? a : b);
}

int query(int p, int s, int e, int qs, int qe)
{
	if (qs <= s && e <= qe) return t[p];
	if (e < qs || qe < s) return 0;
	int m = (s + e) >> 1;
	int a = query((p << 1), s, m, qs, qe);
	int b = query((p << 1) | 1, m + 1, e, qs, qe);
	return (n[a] <= n[b] ? a : b);
}

int update(int p, int s, int e, int i, int v)
{
	if (i < s || e < i) return t[p];
	if (s == e)
	{
		n[i] = v;
		return i;
	}
	int m = (s + e) >> 1;
	int a = update((p << 1), s, m, i, v);
	int b = update((p << 1) | 1, m + 1, e, i, v);
	return t[p] = (n[a] <= n[b] ? a : b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, a, b, c;
	cin >> N;
	n[0] = 1'000'000'010;
	for (int i = 1; i <= N; ++i) cin >> n[i];
	init(1, 1, N);
	cin >> M;
	for (int i = 1; i <= M; ++i)
	{
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, N, b, c);
		else cout << query(1, 1, N, b, c) << '\n';
	}

	return 0;
}
