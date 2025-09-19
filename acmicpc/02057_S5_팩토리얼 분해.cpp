#include <iostream>

using namespace std;
using ll = long long;

ll fac[25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fac[0] = 1;
	ll tmp = 1;
	for (int i = 1; i <= 20; ++i)
	{
		tmp *= i;
		fac[i] = tmp;
	}

	ll N;
	cin >> N;
	if (!N)
	{
		cout << "NO";
		return 0;
	}

	ll left = N;
	for (int i = 20; i >= 0; --i)
	{
		if (!left) break;
		if (left < fac[i]) continue;
		if (left > fac[i] * (i + 1))
		{
			cout << "NO";
			return 0;
		}

		left -= fac[i];
	}

	if (left) cout << "NO";
	else cout << "YES";

	return 0;
}
