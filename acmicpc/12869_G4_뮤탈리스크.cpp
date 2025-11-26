#include <iostream>
#include <algorithm>
#include <array>
#include <queue>

using namespace std;

const int pat[6][3] =
{
	{1, 3, 9},
	{1, 9, 3},
	{3, 1, 9},
	{3, 9, 1},
	{9, 1, 3},
	{9, 3, 1}
};

int n;
int h[3];
int tb[65][65][65];
queue<array<int, 3>> que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> h[i];

	for (int i = 0; i <= 60; ++i)
	{
		for (int j = 0; j <= 60; ++j)
		{
			for (int k = 0; k <= 60; ++k) tb[i][j][k] = 100'000'000;
		}
	}

	int a = h[0];
	int b = h[1];
	int c = h[2];
	que.push({ a, b, c });
	tb[a][b][c] = 0;

	while (!que.empty())
	{
		array<int, 3> cur = que.front();
		que.pop();
		a = cur[0];
		b = cur[1];
		c = cur[2];
		int cnt = tb[a][b][c];

		if (!a && !b && !c) break;

		for (int t = 0; t < 6; ++t)
		{
			int na = max(0, a - pat[t][0]);
			int nb = max(0, b - pat[t][1]);
			int nc = max(0, c - pat[t][2]);

			if (tb[na][nb][nc] > cnt + 1)
			{
				que.push({ na, nb, nc });
				tb[na][nb][nc] = cnt + 1;
			}
		}
	}

	cout << tb[0][0][0];

	return 0;
}
