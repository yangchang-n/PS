#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, r, c;
	cin >> N >> r >> c;

	int rt[15] = {};
	int ct[15] = {};

	for (int i = 0; i < N; ++i)
	{
		rt[i] = (r & 1);
		ct[i] = (c & 1);

		r >>= 1;
		c >>= 1;
	}

	int ans = 0;
	for (int i = N - 1; i > 0; --i)
	{
		ans += rt[i];
		ans <<= 1;
		ans += ct[i];
		ans <<= 1;
	}
	ans += rt[0];
	ans <<= 1;
	ans += ct[0];

	cout << ans;

	return 0;
}
