#include <iostream>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N;
	cin >> N;

	ll ans = 0;
	if (N % 2) ans = (N + 1) * (N * N * 2 + N * 3 - 1) / 8;
	else ans = N * (N + 2) * (N * 2 + 1) / 8;

	cout << ans;

	return 0;
}
