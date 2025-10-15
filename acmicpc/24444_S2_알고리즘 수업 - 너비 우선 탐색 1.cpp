#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, R;
vector<vector<int>> edge(100'010);
vector<int> order(100'010, 0);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> R;
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		edge[s].push_back(e);
		edge[e].push_back(s);
	}

	for (int i = 1; i <= N; ++i)
	{
		sort(edge[i].begin(), edge[i].end());
	}

	int cnt = 1;
	queue<int> que;
	que.push(R);
	order[R] = cnt++;

	while (!que.empty())
	{
		int c = que.front();
		que.pop();

		for (int n : edge[c])
		{
			if (order[n]) continue;
			que.push(n);
			order[n] = cnt++;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << order[i] << '\n';
	}

	return 0;
}
