#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<ll> a(n + 1);
	vector<ll> b(m + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) cin >> b[i];

	if (n > m)
	{
		swap(n, m);
		swap(a, b);
	}
	sort(a.begin() + 1, a.end());
	sort(b.begin() + 1, b.end());

	vector<vector<ll>> tb(n + 1, vector<ll>(m + 1));
	tb[0][0] = 0LL;
	for (int i = 1; i <= n; ++i)
	{
		tb[i][i] = tb[i - 1][i - 1] + llabs(a[i] - b[i]);
		for (int j = i + 1; j <= i + m - n; ++j)
		{
			ll skip  = tb[i][j - 1];
			ll match = tb[i - 1][j - 1] + llabs(a[i] - b[j]);
			tb[i][j] = min(skip, match);
		}
	}

	cout << tb[n][m];

	return 0;
}
