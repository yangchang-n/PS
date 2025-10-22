#include <iostream>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, b;
	cin >> a >> b;

	if (a % 2) a++;
	if (b % 2) b--;
	a >>= 1;
	b >>= 1;
	if (a == 1) a++;
	if (a > b)
	{
		cout << 0;
		return 0;
	}

	ll ans = (a + b) * (b - a + 1);
	cout << ans;

	return 0;
}
