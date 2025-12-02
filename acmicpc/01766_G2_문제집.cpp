#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ind[32010];
vector<int> nxt[32010];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		ind[b]++;
		nxt[a].push_back(b);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!ind[i]) pq.push(i);
	}

	while (!pq.empty())
	{
		int c = pq.top();
		pq.pop();

		cout << c << ' ';

		for (int n : nxt[c])
		{
			ind[n]--;
			if (!ind[n]) pq.push(n);
		}
	}

	return 0;
}
