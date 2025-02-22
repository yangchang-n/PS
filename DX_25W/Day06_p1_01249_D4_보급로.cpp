// #ifndef _CRT_SECURE_NO_WARNINGS
// #define _CRT_SECURE_NO_WARNINGS
// #endif

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 10000;
const int MAX_N = 101;

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

int grid[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
char grid_line[MAX_N];

int dijkstra(int n)
{
	int N = n;
	using node = pair<int, pair<int, int>>;
	priority_queue<node, vector<node>, greater<node>> pq;

	pq.push({ grid[0][0], {0, 0} });
	while (!pq.empty())
	{
		node cur = pq.top();
		int cost = cur.first;
		int cy = cur.second.first;
		int cx = cur.second.second;
		pq.pop();

		if (cost > dist[cy][cx]) continue;

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

			int ncost = cost + grid[ny][nx];
			if (ncost < dist[ny][nx])
			{
				dist[ny][nx] = ncost;
				pq.push({ ncost, {ny, nx} });
			}
		}
	}

	return dist[N - 1][N - 1];
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N;
		cin >> N;
		cin.ignore();

		for (int i = 0; i < N; ++i)
		{
			cin.getline(grid_line, 101);
			for (int j = 0; j < N; ++j)
			{
				grid[i][j] = grid_line[j] - '0';
				dist[i][j] = INF;
			}
		}
		dist[0][0] = grid[0][0];

		int ans = dijkstra(N);

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}
