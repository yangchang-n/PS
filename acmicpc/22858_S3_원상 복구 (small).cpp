#include <iostream>

using namespace std;

int n, k;
int s[10010];
int d[10010];
int t[10010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> s[i];
	for (int i = 1; i <= n; ++i) cin >> d[i];

	for (int c = 1; c <= k; ++c)
	{
		if (c % 2)
		{
			for (int i = 1; i <= n; ++i) t[d[i]] = s[i];
		}
		else
		{
			for (int i = 1; i <= n; ++i) s[d[i]] = t[i];
		}
	}

	if (k % 2)
	{
		for (int i = 1; i <= n; ++i) cout << t[i] << ' ';
	}
	else
	{
		for (int i = 1; i <= n; ++i) cout << s[i] << ' ';
	}

	return 0;
}
