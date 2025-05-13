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
		int B, W, X, Y, Z;
		cin >> B >> W >> X >> Y >> Z;

		int mn = min(B, W);
		bool mix = (Z << 1) > X + Y;

		int ans = 0;
		if (mix)
		{
			ans += (Z * mn) << 1;
			ans += (B - mn) * X;
			ans += (W - mn) * Y;
		}
		else
		{
			ans += B * X + W * Y;
		}

		cout << ans << '\n';
	}

	return 0;
}
