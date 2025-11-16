#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

double p[8][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 8; i += 2) cin >> p[i][0] >> p[i][1];
	for (int i = 1; i < 8; i += 2)
	{
		double x = (p[i - 1][0] + p[(i + 1) % 8][0]) / 2.0;
		double y = (p[i - 1][1] + p[(i + 1) % 8][1]) / 2.0;
		p[i][0] = x;
		p[i][1] = y;
	}

	double tmp[2] = {};
	double ans[2] = { 1.0, 100'000'000.0 };
	for (int i = 0; i < 8; ++i)
	{
		for (int j = i + 1; j < 8; ++j)
		{
			if ((j - 1) % 8 == i) continue;
			if ((j + 1) % 8 == i) continue;
			if ((j - 2) % 8 == i && i % 2 == 0) continue;
			if ((j + 2) % 8 == i && i % 2 == 0) continue;

			tmp[0] = tmp[1] = 0.0;

			int a = i;
			int b = (i + 1) % 8;
			while (true)
			{
				if (b == (j + 1) % 8) b = i;
				tmp[0] += p[a][0] * p[b][1] - p[b][0] * p[a][1];
				if (b == i) break;
				a = (a + 1) % 8;
				b = (b + 1) % 8;
			}
			tmp[0] = fabs(tmp[0]) / 2.0;

			a = j;
			b = (j + 1) % 8;
			while (true)
			{
				if (b == (i + 1) % 8) b = j;
				tmp[1] += p[a][0] * p[b][1] - p[b][0] * p[a][1];
				if (b == j) break;
				a = (a + 1) % 8;
				b = (b + 1) % 8;
			}
			tmp[1] = fabs(tmp[1]) / 2.0;

			double mx = max(tmp[0], tmp[1]);
			double mn = min(tmp[0], tmp[1]);
			if (mx / mn < ans[1] / ans[0])
			{
				ans[0] = mn;
				ans[1] = mx;
			}
		}
	}

	cout << fixed << setprecision(5) << ans[0] << ' ' << ans[1];

	return 0;
}
