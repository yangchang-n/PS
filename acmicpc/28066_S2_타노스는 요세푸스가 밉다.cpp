#include <iostream>
#include <queue>

using namespace std;

queue<int> que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) que.push(i);

	while (!que.empty())
	{
		if (que.size() <= K)
		{
			cout << que.front();
			break;
		}

		int c = que.front();
		que.push(c);
		for (int i = 1; i <= K; ++i) que.pop();
	}

	return 0;
}
