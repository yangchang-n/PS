#include <iostream>

using namespace std;
using ll = long long;

ll tb[60];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	tb[0] = tb[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		tb[i] = tb[i - 1] + tb[i - 2] + 1;
		while (tb[i] >= 1'000'000'007) tb[i] -= 1'000'000'007;
	}

	cout << tb[n];

	return 0;
}
