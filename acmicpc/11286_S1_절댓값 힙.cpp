#include <iostream>
#include <array>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int sz = 0, num, tmp;
	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;

	for (int i = 0; i < N; ++i)
	{
		cin >> num;

		if (num)
		{
			tmp = abs(num);
			pq.push({ tmp, num });
			sz++;
		}
		else if (sz)
		{
			cout << pq.top()[1] << '\n';
			pq.pop();
			sz--;
		}
		else cout << 0 << '\n';
	}

	return 0;
}
