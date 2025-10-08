#include <iostream>
#include <algorithm>

using namespace std;

int h[1'000'010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int r, c, n;
	cin >> r >> c >> n;
	for (int i = 0; i < n; ++i) cin >> h[i];
	sort(h, h + n);

	int ans = 0;
	int cnt = 1;
	int pre = 0;
	for (int i = 0; i < n; ++i)
	{
		if (h[i] == pre)
		{
			if (cnt < c)
			{
				cnt++;
				ans++;
			}
		}
		else
		{
			cnt = 1;
			ans++;
		}

		pre = h[i];
	}

	if (ans > r * c) cout << r * c;
	else cout << ans;

	return 0;
}
