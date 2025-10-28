#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Cycle
{
	ll start = 0;
	ll order = 0;
	vector<ll> seq;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, k;
	cin >> n >> k;
	vector<ll> s(n + 1);
	vector<ll> d(n + 1);
	for (ll i = 1; i <= n; ++i) cin >> s[i];
	for (ll i = 1; i <= n; ++i) cin >> d[i];

	vector<Cycle> cy(n + 1);
	vector<bool> done(n + 1, false);
	for (ll i = 1; i <= n; ++i)
	{
		if (done[i]) continue;

		cy[i].start = i;
		cy[i].order = 0;
		cy[i].seq.push_back(i);
		done[i] = true;

		ll pre = i;
		ll cnt = 1;
		while (true)
		{
			ll cur = d[pre];
			if (cur == i) break;
			if (done[cur]) break;

			cy[cur].start = i;
			cy[cur].order = cnt++;
			cy[i].seq.push_back(cur);
			done[cur] = true;

			pre = cur;
		}
	}

	vector<ll> ans(n + 1);
	for (ll i = 1; i <= n; ++i)
	{
		ll cs = cy[i].start;
		ll co = cy[i].order;
		ll fo = (k + co) % cy[cs].seq.size();
		ll fd = cy[cs].seq[fo];

		ans[fd] = s[i];
	}

	for (ll i = 1; i <= n; ++i) cout << ans[i] << ' ';

	return 0;
}
