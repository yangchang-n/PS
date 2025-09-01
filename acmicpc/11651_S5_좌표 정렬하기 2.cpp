#include <iostream>
#include <array>
#include <queue>

using namespace std;

int N;
priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		pq.push({ y, x });
	}

	while (!pq.empty())
	{
		array<int, 2> cur = pq.top();
		pq.pop();
		cout << cur[1] << ' ' << cur[0] << '\n';
	}

	return 0;
}
