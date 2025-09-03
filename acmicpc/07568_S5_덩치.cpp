#include <iostream>

using namespace std;

int N;
int dat[60][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> dat[i][0] >> dat[i][1];

	for (int i = 0; i < N; ++i)
	{
		int ans = 1;
		int x = dat[i][0];
		int y = dat[i][1];

		for (int j = 0; j < N; ++j)
		{
			int cx = dat[j][0];
			int cy = dat[j][1];

			if (cx <= x) continue;
			if (cy <= y) continue;

			ans++;
		}

		cout << ans << ' ';
	}

	return 0;
}
