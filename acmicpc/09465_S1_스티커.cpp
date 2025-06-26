#include <iostream>

using namespace std;

int n;
int st[2][100010];
int tb[2][100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> st[0][i];
		for (int i = 0; i < n; ++i) cin >> st[1][i];

		if (n == 1)
		{
			cout << max(st[0][0], st[1][0]) << '\n';
			continue;
		}

		tb[0][0] = st[0][0];
		tb[1][0] = st[1][0];
		tb[0][1] = st[1][0] + st[0][1];
		tb[1][1] = st[0][0] + st[1][1];

		for (int i = 2; i < n; ++i)
		{
			tb[0][i] = st[0][i] + max(tb[1][i - 1], tb[1][i - 2]);
			tb[1][i] = st[1][i] + max(tb[0][i - 1], tb[0][i - 2]);
		}

		cout << max(tb[0][n - 1], tb[1][n - 1]) << '\n';
	}

	return 0;
}
