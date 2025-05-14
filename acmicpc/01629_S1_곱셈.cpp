#include <iostream>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, e, m;
	cin >> a >> e >> m;

	ll ans = 1;
	while (e > 0)
	{
		if (e & 1) ans = (ans * a) % m;
		a = (a * a) % m;
		e >>= 1;
	}

	cout << ans;

	return 0;
}
