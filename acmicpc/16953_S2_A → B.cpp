#include <iostream>
#include <array>
#include <queue>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll A, B;
	cin >> A >> B;

	priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
	pq.push({ A, 1LL });

	ll ans = 100LL;
	while (!pq.empty())
	{
		array<ll, 2> cur = pq.top();
		pq.pop();

		if (cur[0] > B) break;
		if (cur[0] == B) ans = min(ans, cur[1]);

		pq.push({ (cur[0] << 1), cur[1] + 1 });
		pq.push({ (cur[0] * 10 + 1), cur[1] + 1 });
	}

	if (ans == 100) cout << -1;
	else cout << ans;

	return 0;
}
