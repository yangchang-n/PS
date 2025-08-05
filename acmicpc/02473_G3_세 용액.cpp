#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int N;
ll ph[5010];
ll ans[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> ph[i];
	sort(ph, ph + N);

	if (ph[0] >= 0)
	{
		cout << ph[0] << ' ' << ph[1] << ' ' << ph[2];
		return 0;
	}
	else if (ph[N - 1] <= 0)
	{
		cout << ph[N - 3] << ' ' << ph[N - 2] << ' ' << ph[N - 1];
		return 0;
	}

	ll tmp = 0;
	ll pre = 3'000'000'010;

	for (int i = 0; i < N - 2; ++i)
	{
		ll a = ph[i];
		int s = i + 1;
		int e = N - 1;

		while (s < e)
		{
			tmp = a + ph[s] + ph[e];

			if (abs(tmp) < pre)
			{
				pre = abs(tmp);
				ans[0] = a;
				ans[1] = ph[s];
				ans[2] = ph[e];
			}

			if (tmp == 0)
			{
				cout << a << ' ' << ph[s] << ' ' << ph[e];
				return 0;
			}
			else if (tmp < 0) s++;
			else if (tmp > 0) e--;
		}
	}

	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];

	return 0;
}
