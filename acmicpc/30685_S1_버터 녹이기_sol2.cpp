#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;
using ll = long long;
using al2 = array<ll, 2>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, x, h;
	cin >> n;
	vector<al2> vt(n);
	for (ll i = 0; i < n; ++i)
	{
		cin >> x >> h;
		vt[i][0] = x;
		vt[i][1] = h;
	}

	sort(vt.begin(), vt.end());

	ll ans = 10'000'000'000LL;
	al2 pre = vt[0];
	for (ll i = 1; i < n; ++i)
	{
		al2 cur = vt[i];
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
