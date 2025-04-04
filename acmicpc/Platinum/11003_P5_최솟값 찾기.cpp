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

	deque<array<int, 2>> dq;

	for (int i = 1; i <= N; ++i)
	{
		cin >> num;

		while (!dq.empty() && dq.front()[1] <= i - L) dq.pop_front();
		while (!dq.empty() && dq.back()[0] >= num) dq.pop_back();

		dq.push_back({ num, i });

		cout << dq.front()[0] << ' ';
	}

	return 0;
}
