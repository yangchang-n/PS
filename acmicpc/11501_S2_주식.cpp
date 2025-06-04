#include <iostream>

using namespace std;
using ll = long long;

ll stock[1'000'010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N;
		cin >> N;

		for (int i = 0; i < N; ++i) cin >> stock[i];

		ll ans = 0, best = 0, bud = 0;
		int cnt = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			if (best < stock[i])
			{
				ans += best * cnt - bud;
				best = stock[i];
				bud = 0, cnt = 0;
			}
			else
			{
				bud += stock[i];
				cnt++;
			}
		}
		ans += best * cnt - bud;

		cout << ans << '\n';
	}

	return 0;
}
