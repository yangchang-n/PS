#include <iostream>
#include <array>
#include <queue>

using namespace std;

const int di[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
const int dj[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

bool vis[300][300];

int bfs_knight(int I, int si, int sj, int ei, int ej)
{
	int ans = 0;

	for (int i = 0; i < I; ++i)
	{
		for (int j = 0; j < I; ++j) vis[i][j] = false;
	}

	queue<array<int, 3>> que;
	que.push({ 0, si, sj });
	vis[si][sj] = true;

	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();

		if (cur[1] == ei && cur[2] == ej)
		{
			ans = cur[0];
			break;
		}

		for (int d = 0; d < 8; ++d)
		{
			int ni = cur[1] + di[d];
			int nj = cur[2] + dj[d];

			if (ni < 0 || ni >= I) continue;
			if (nj < 0 || nj >= I) continue;
			if (vis[ni][nj]) continue;

			que.push({ cur[0] + 1, ni, nj });
			vis[ni][nj] = true;
		}
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int I, si, sj, ei, ej;
		cin >> I;
		cin >> si >> sj;
		cin >> ei >> ej;

		int ans = bfs_knight(I, si, sj, ei, ej);

		cout << ans << '\n';
	}

	return 0;
}
