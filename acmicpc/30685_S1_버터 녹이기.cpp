#include <iostream>
#include <algorithm>
#include <array>
#include <queue>

using namespace std;
using ll = long long;
using al2 = array<ll, 2>;

priority_queue<al2, vector<al2>, greater<al2>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, x, h;
	cin >> n;
	for (ll i = 0; i < n; ++i)
	{
		cin >> x >> h;
		pq.push({ x, h });
	}

	ll ans = 10'000'000'000LL;
	al2 pre = pq.top();
	pq.pop();

	while (!pq.empty())
	{
		al2 cur = pq.top();
		pq.pop();

		ll ph = pre[1] / 2;
		ll ch = cur[1] / 2;
		ll ds = cur[0] - pre[0];

		if (ph + ch < ds)
		{
			pre = cur;
			continue;
		}

		ll dh = ds / 2;
		if (ds % 2) dh++;

		if (ph >= dh && ch >= dh)
		{
			ans = min(ans, dh - 1);
		}
		else if (ph < dh)
		{
			ans = min(ans, cur[0] - pre[0] - ph - 1);
		}
		else if (ch < dh)
		{
			ans = min(ans, cur[0] - pre[0] - ch - 1);
		}

		pre = cur;
	}

	if (ans == 10'000'000'000LL) cout << "forever";
	else cout << ans;

	return 0;
}
