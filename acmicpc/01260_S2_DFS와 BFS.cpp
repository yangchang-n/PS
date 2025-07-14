#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int N, M, V;
unordered_map<int, vector<int>> um;
vector<bool> vs(1010, false);
vector<int> dfs_order;
vector<int> bfs_order;

void dfs()
{
	fill(vs.begin(), vs.end(), 0);
	deque<int> dq;

	dq.push_back(V);

	while (!dq.empty())
	{
		int cur = dq.back();
		dq.pop_back();
		if (vs[cur]) continue;

		dfs_order.push_back(cur);
		vs[cur] = true;

		for (auto itr = um[cur].rbegin(); itr != um[cur].rend(); ++itr)
		{
			if (vs[*itr]) continue;
			dq.push_back(*itr);
		}
	}
}

void bfs()
{
	fill(vs.begin(), vs.end(), 0);
	queue<int> qu;

	qu.push(V);
	vs[V] = true;

	while (!qu.empty())
	{
		int cur = qu.front();
		qu.pop();

		bfs_order.push_back(cur);

		for (auto itr = um[cur].begin(); itr != um[cur].end(); ++itr)
		{
			if (vs[*itr]) continue;
			qu.push(*itr);
			vs[*itr] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> V;

	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;

		if (!um.count(s)) um[s] = vector<int>();
		if (!um.count(e)) um[e] = vector<int>();

		um[s].push_back(e);
		um[e].push_back(s);
	}

	for (auto itr = um.begin(); itr != um.end(); ++itr)
	{
		vector<int>& vt = (*itr).second;
		sort(vt.begin(), vt.end());
	}

	dfs();
	bfs();

	for (int i : dfs_order) cout << i << ' ';
	cout << '\n';
	for (int i : bfs_order) cout << i << ' ';

	return 0;
}
