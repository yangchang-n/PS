#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;
using ai2 = array<int, 2>;

vector<int> vs(10010, 0);
vector<ai2> ed[10010];
priority_queue<ai2, vector<ai2>, greater<ai2>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, T, a, b, c;
	cin >> N >> M >> T;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b >> c;
		ed[a].push_back({ b, c });
		ed[b].push_back({ a, c });
	}

	int ans = 0;
	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		int cc = pq.top()[0];
		int cn = pq.top()[1];
		pq.pop();

		if (vs[cn]) continue;

		ans += cc;
		vs[cn] = 1;

		for (ai2 e : ed[cn])
		{
			int nn = e[0];
			int nc = e[1];
			if (vs[nn]) continue;
			pq.push({ nc, nn });
		}
	}

	if (N >= 3) ans += (N - 1) * (N - 2) / 2 * T;
	cout << ans;

	return 0;
}
