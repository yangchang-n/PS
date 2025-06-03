#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll A, B;
	cin >> A >> B;

	queue<pair<ll, int>> que;
	que.push({ A, 1 });

	int ans = -1;
	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();

		if (cur.first == B)
		{
			ans = cur.second;
			break;
		}
		if (cur.first << 1 <= B)
		{
			que.push({ (cur.first << 1), cur.second + 1 });
		}
		if (cur.first * 10 + 1 <= B)
		{
			que.push({ (cur.first * 10 + 1), cur.second + 1 });
		}
	}

	cout << ans;

	return 0;
}
