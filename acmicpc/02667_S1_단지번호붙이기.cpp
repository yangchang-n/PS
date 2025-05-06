#include <iostream>
#include <array>
#include <queue>

using namespace std;

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };

int N, cnt;
int map[25][25];
int vis[25][25];
priority_queue<int, vector<int>, greater<int>> pq;

void bfs_apm()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] && !vis[i][j])
			{
				cnt++;
				int sz = 0;
				queue<array<int, 2>> que;

				que.push({ i, j });
				vis[i][j] = 1;
				sz++;

				while (!que.empty())
				{
					int ci = que.front()[0];
					int cj = que.front()[1];
					que.pop();

					for (int d = 0; d < 4; ++d)
					{
						int ni = ci + di[d];
						int nj = cj + dj[d];

						if (ni < 0 || ni >= N) continue;
						if (nj < 0 || nj >= N) continue;
						if (!map[ni][nj]) continue;
						if (vis[ni][nj]) continue;

						que.push({ ni, nj });
						vis[ni][nj] = 1;
						sz++;
					}
				}

				pq.push(sz);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	cnt = 0;

	for (int i = 0; i < N; ++i)
	{
		string r;
		cin >> r;
		for (int j = 0; j < N; ++j)
		{
			map[i][j] = r[j] - '0';
			vis[i][j] = 0;
		}
	}

	bfs_apm();

	cout << cnt << '\n';
	while (!pq.empty())
	{
		cout << pq.top() << '\n';
		pq.pop();
	}

	return 0;
}
