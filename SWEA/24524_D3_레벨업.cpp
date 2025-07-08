#include <iostream>
#include <algorithm>

using namespace std;

int chk[50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, N;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		for (int i = 0; i < N; ++i) cin >> chk[i];

		int ans = abs(chk[1] - chk[0]);
		int skp = 0, tmp;
		for (int i = 2; i < N; ++i)
		{
			ans += abs(chk[i] - chk[i - 1]);
			tmp = abs(chk[i] - chk[i - 1])
				+ abs(chk[i - 1] - chk[i - 2])
				- abs(chk[i] - chk[i - 2]);
			skp = max(skp, tmp);
		}

		cout << ans - skp << '\n';
	}

	return 0;
}
