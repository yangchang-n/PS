#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ind[1010];
vector<int> nnd[1010];
queue<int> que;
queue<int> ord;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, c, p, t;
	cin >> N >> M;
	for (int pd = 1; pd <= M; ++pd)
	{
		cin >> c >> p;
		for (int i = 1; i < c; ++i)
		{
			cin >> t;
			ind[t]++;
			nnd[p].push_back(t);
			p = t;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!ind[i]) que.push(i);
	}

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();
		ord.push(cur);
		for (int nxt : nnd[cur])
		{
			ind[nxt]--;
			if (!ind[nxt]) que.push(nxt);
		}
	}

	if (ord.size() == N)
	{
		while (!ord.empty())
		{
			cout << ord.front() << '\n';
			ord.pop();
		}
	}
	else cout << 0;

	return 0;
}
