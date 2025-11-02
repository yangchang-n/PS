#include <iostream>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	if (n < 0) n = 0 - n;

	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	else if (n % 2 == 0)
	{
		cout << -1;
		return 0;
	}

	ll t = 2;
	ll cnt = 1;
	while (true)
	{
		if (cnt > 45) break;
		if (n < t)
		{
			cout << cnt;
			break;
		}
		t *= 2;
		cnt++;
	}

	return 0;
}
