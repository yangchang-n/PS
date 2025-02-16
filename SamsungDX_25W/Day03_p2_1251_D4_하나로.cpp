#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

// start

#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

typedef long long ll;

ll island_x[1000], island_y[1000];
ll island_len[1000][1000];
ll len_diff_x, len_diff_y, len_sq;
ll mst_cost;
bool visited[1000];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin); // have to erase

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		for (int i = 0; i < N; ++i) cin >> island_x[i];
		for (int i = 0; i < N; ++i) cin >> island_y[i];

		double E;
		cin >> E;

		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				len_diff_x = island_x[j] - island_x[i];
				len_diff_y = island_y[j] - island_y[i];
				len_sq = len_diff_x * len_diff_x + len_diff_y * len_diff_y;

				island_len[i][j] = len_sq;
				island_len[j][i] = len_sq;
			}
		}

		mst_cost = 0;
		for (int i = 0; i < N; ++i) visited[i] = false;

		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({0, 0});

		while (!pq.empty())
		{
			ll cost = pq.top().first;
			int node = pq.top().second;
			pq.pop();

			if (visited[node]) continue;

			visited[node] = true;
			mst_cost += cost;

			for (int i = 0; i < N; ++i)
			{
				if (!visited[i]) pq.push({island_len[node][i], i});
			}
		}

		mst_cost = round(mst_cost * E);

		cout << '#' << test_case << ' ' <<mst_cost << '\n';
	}

	return 0;
}
