#include <iostream>

using namespace std;

int cnt[16];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cnt[1] = 1;
	cnt[2] = 2;
	cnt[3] = 4;
	for (int i = 4; i < 11; ++i)
	{
		cnt[i] = cnt[i - 1] + cnt[i - 2] + cnt[i - 3];
	}

	int T, N;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		cout << cnt[N] << '\n';
	}

	return 0;
}
