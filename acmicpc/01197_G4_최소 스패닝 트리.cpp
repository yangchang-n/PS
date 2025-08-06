#include <iostream>
#include <array>
#include <vector>
#include <queue>

using namespace std;

int V, E, ans = 0;
bool vis[10010];
vector<array<int, 2>> ed[10010];
priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> V >> E;
	for (int i = 0; i < E; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		ed[a].push_back({ b, c });
		ed[b].push_back({ a, c });
	}

	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		int cc = pq.top()[0];
		int cn = pq.top()[1];
		pq.pop();

		if (vis[cn]) continue;

		vis[cn] = true;
		ans += cc;

		for (int i = 0; i < ed[cn].size(); ++i)
		{
			int nn = ed[cn][i][0];
			int nc = ed[cn][i][1];

			if (vis[nn]) continue;
			pq.push({ nc, nn });
		}
	}

	cout << ans;

	return 0;
}
