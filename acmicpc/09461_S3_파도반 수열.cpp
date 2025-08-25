#include <iostream>

using namespace std;
using ll = long long;

ll p[110] = { 0, 1, 1, 1, 2, 2 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 6; i <= 100; ++i)
	{
		p[i] = p[i - 1] + p[i - 5];
	}

	int T, N;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		cout << p[N] << '\n';
	}

	return 0;
}
