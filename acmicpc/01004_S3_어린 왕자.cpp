#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int ans = 0;
		int x1, y1, x2, y2, cx, cy, r, n;
		cin >> x1 >> y1 >> x2 >> y2 >> n;

		for (int i = 0; i < n; ++i)
		{
			int out = 0;
			cin >> cx >> cy >> r;

			if ((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1) > r * r) out++;
			if ((cx - x2) * (cx - x2) + (cy - y2) * (cy - y2) > r * r) out++;
			if (out % 2) ans++;
		}

		cout << ans << '\n';
	}

	return 0;
}
