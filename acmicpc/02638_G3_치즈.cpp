#include <iostream>
#include <array>
#include <vector>
#include <queue>

using namespace std;

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };

int N, M, cnt = 0;
int brd[100][100];
int out[100][100];
vector<array<int, 2>> melting;

void bfs_outside(int i, int j)
{
	if (brd[i][j]) return;
	if (out[i][j]) return;

	queue<array<int, 2>> que;
	que.push({ i, j });
	out[i][j] = 1;

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
			if (nj < 0 || nj >= M) continue;
			if (brd[ni][nj]) continue;
			if (out[ni][nj]) continue;

			que.push({ ni, nj });
			out[ni][nj] = 1;
		}
	}
}

void check_cheese()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!brd[i][j]) continue;

			int edge = 0;
			for (int d = 0; d < 4; ++d)
			{
				int ni = i + di[d];
				int nj = j + dj[d];

				if (out[ni][nj]) edge++;
				if (edge >= 2)
				{
					melting.push_back({ i, j });
					brd[i][j] = 0;
					cnt--;
					break;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> tmp;
			brd[i][j] = tmp;
			// out[i][j] = 0;
			if (tmp) cnt++;
		}
	}

	int hrs = 0;
	melting.push_back({ 0, 0 });

	while (cnt)
	{
		hrs++;
		for (auto cur : melting) bfs_outside(cur[0], cur[1]);
		melting.clear();
		check_cheese();
	}

	cout << hrs;

	return 0;
}
