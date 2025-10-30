#include <iostream>
#include <array>
#include <queue>

using namespace std;

const int di[4] = { 0, 0, 1, -1 };
const int dj[4] = { 1, -1, 0, 0 };

bool bd[1010][1010];
bool vs[1010][1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			char c;
			cin >> c;
			bd[i][j] = (c == '0' ? 1 : 0);
		}
	}

	queue<array<int, 2>> que;
	for (int i = 0; i < n; ++i)
	{
		if (!bd[0][i]) continue;
		que.push({ 0, i });
		vs[0][i] = 1;
	}

	while (!que.empty())
	{
		array<int, 2> cur = que.front();
		int ci = cur[0];
		int cj = cur[1];
		que.pop();

		for (int d = 0; d < 4; ++d)
		{
			int ni = ci + di[d];
			int nj = cj + dj[d];

			if (ni < 0 || ni >= m) continue;
			if (nj < 0 || nj >= n) continue;
			if (!bd[ni][nj]) continue;
			if (vs[ni][nj]) continue;

			que.push({ ni, nj });
			vs[ni][nj] = 1;
		}
	}

	bool good = false;
	for (int i = 0; i < n; ++i)
	{
		if (!bd[m - 1][i]) continue;
		if (vs[m - 1][i])
		{
			good = true;
			break;
		}
	}

	cout << (good ? "YES" : "NO");

	return 0;
}
