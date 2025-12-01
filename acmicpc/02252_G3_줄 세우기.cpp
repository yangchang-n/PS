#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> ord[32'010];
int ind[32'010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		ord[a].push_back(b);
		ind[b]++;
	}

	queue<int> que;
	for (int i = 1; i <= N; ++i)
	{
		if (!ind[i]) que.push(i);
	}

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		cout << cur << ' ';

		for (int nxt : ord[cur])
		{
			ind[nxt]--;
			if (!ind[nxt]) que.push(nxt);
		}
	}

	return 0;
}
