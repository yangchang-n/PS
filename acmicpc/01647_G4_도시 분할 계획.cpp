#include <iostream>
#include <array>
#include <vector>
#include <queue>

using namespace std;

int N, M, ans = 0;
bool vis[100'010];
vector<array<int, 2>> ed[100'010];
priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		ed[a].push_back({ b, c });
		ed[b].push_back({ a, c });
	}

	pq.push({ 0, 1 });
	int far = 0;

	while (!pq.empty())
	{
		int cc = pq.top()[0];
		int cn = pq.top()[1];
		pq.pop();

		if (vis[cn]) continue;

		vis[cn] = true;
		ans += cc;
		far = max(far, cc);

		for (int i = 0; i < ed[cn].size(); ++i)
		{
			int nn = ed[cn][i][0];
			int nc = ed[cn][i][1];

			if (vis[nn]) continue;
			pq.push({ nc, nn });
		}
	}

	cout << ans - far;

	return 0;
}
