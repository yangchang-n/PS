#include <iostream>

using namespace std;

int T, N;
int cnt[50][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cnt[0][0] = 1;
	cnt[0][1] = 0;
	cnt[1][0] = 0;
	cnt[1][1] = 1;

	for (int i = 2; i <= 40; ++i)
	{
		cnt[i][0] = cnt[i - 1][0] + cnt[i - 2][0];
		cnt[i][1] = cnt[i - 1][1] + cnt[i - 2][1];
	}

	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		cout << cnt[N][0] << ' ';
		cout << cnt[N][1] << '\n';
	}

	return 0;
}
