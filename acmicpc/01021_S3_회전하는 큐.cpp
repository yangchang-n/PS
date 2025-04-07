#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

#include <iostream>
#include <algorithm>
#include <queue>

int main()
{
	fastIO;

	int N, M, num;
	cin >> N >> M;

	deque<int> dq;
	for (int i = 1; i <= N; ++i) dq.push_back(i);

	int ans = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> num;
		int idx = find(dq.begin(), dq.end(), num) - dq.begin();

		if (idx <= N / 2)
		{
			ans += idx;
			while (idx--)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			idx = N - idx;
			ans += idx;
			while (idx--)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}

		dq.pop_front();
		N--;
	}

	cout << ans;

	return 0;
}
