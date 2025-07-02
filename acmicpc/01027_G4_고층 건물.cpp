#include <iostream>

using namespace std;
using ld = long double;

ld bd[60];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, ans = 0;
	cin >> N;

	for (int i = 0; i < N; ++i) cin >> bd[i];

	for (int b = 0; b < N; ++b)
	{
		int cnt = 0;

		for (int i = 0; i < N; ++i)
		{
			if (i == b) continue;

			if (i == b - 1 || i == b + 1)
			{
				cnt++;
				continue;
			}

			bool visible = true;

			if (i < b)
			{
				for (int t = i + 1; t < b; ++t)
				{
					ld tmp = (bd[b] - bd[i]) * (t - i) / (b - i);
					if (bd[t] - bd[i] >= tmp)
					{
						visible = false;
						break;
					}
				}
			}
			else if (i > b)
			{
				for (int t = b + 1; t < i; ++t)
				{
					ld tmp = (bd[i] - bd[b]) * (t - b) / (i - b);
					if (bd[t] - bd[b] >= tmp)
					{
						visible = false;
						break;
					}
				}
			}

			if (visible) cnt++;
		}

		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}
