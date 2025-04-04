#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

#include <iostream>
#include <array>
#include <queue>

int main()
{
	fastIO;

	int N, L, num;
	cin >> N >> L;

	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;

	for (int i = 1; i <= N; ++i)
	{
		cin >> num;

		pq.push({ num, i });
		while (!pq.empty() && pq.top()[1] <= i - L) pq.pop();

		cout << pq.top()[0] << ' ';
	}

	return 0;
}
