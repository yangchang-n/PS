#include <iostream>

using namespace std;

int n;
int s[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> s[i];

	int ans = 0;
	for (int i = n - 1; i > 0; --i)
	{
		if (s[i] < s[i + 1]) continue;

		ans += s[i] - s[i + 1] + 1;
		s[i] = s[i + 1] - 1;
	}

	cout << ans;

	return 0;
}
