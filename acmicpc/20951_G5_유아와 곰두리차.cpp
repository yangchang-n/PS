#include <iostream>
#include <vector>
#define MOD 1'000'000'007
using namespace std;
using ll = long long;

int N, M;
vector<vector<ll>> ed(100'010);
vector<vector<ll>> cn(100'010, vector<ll>(8));

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= M; ++i)
	{
		int s, e;
		cin >> s >> e;
		ed[s].push_back(e);
		ed[e].push_back(s);
	}

	for (int i = 1; i <= N; ++i) cn[i][1] = ed[i].size();

	for (int d = 2; d <= 7; ++d)
	{
		for (int i = 1; i <= N; ++i)
		{
			ll t = 0;
			for (int n : ed[i]) t += cn[n][d - 1];
			if (t >= MOD) t %= MOD;
			cn[i][d] = t;
		}
	}

	ll ans = 0;
	for (int i = 1; i <= N; ++i) ans += cn[i][7];
	if (ans >= MOD) ans %= MOD;

	cout << ans;

	return 0;
}
