#include <iostream>

using namespace std;

const int MX = 10'000'000;

int N;
int hs[3][1010];
int tb[3][1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> hs[0][i] >> hs[1][i] >> hs[2][i];

	int ans = MX;

	for (int s = 0; s < 3; ++s)
	{
		for (int c = 0; c < 3; ++c)
		{
			if (c == s) tb[c][1] = MX;
			else tb[c][1] = hs[c][1] + hs[s][0];
		}

		for (int i = 2; i < N; ++i)
		{
			tb[0][i] = hs[0][i] + min(tb[1][i - 1], tb[2][i - 1]);
			tb[1][i] = hs[1][i] + min(tb[0][i - 1], tb[2][i - 1]);
			tb[2][i] = hs[2][i] + min(tb[0][i - 1], tb[1][i - 1]);
		}

		for (int c = 0; c < 3; ++c)
		{
			if (c != s) ans = min(ans, tb[c][N - 1]);
		}
	}

	cout << ans;

	return 0;
}
