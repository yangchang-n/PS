#include <iostream>

using namespace std;
using ll = long long;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, x, y;
	cin >> N;

	ll s = -1'000'000'001;
	ll e = -1'000'000'001;
	ll ans = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		if (x > e)
		{
			ans += e - s;
			s = x, e = y;
		}
		else if (y > e) e = y;
	}
	ans += e - s;

	cout << ans;

	return 0;
}
