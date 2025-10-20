#include <iostream>
#include <cstring>

using namespace std;

int w, n;
int p[5'010];
int s[400'010][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> w >> n;
	for (int i = 0; i < n; ++i) cin >> p[i];
	memset(s, -1, sizeof(s));

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int t = p[i] + p[j];
			if (t > w) continue;
			if (s[t][0] != -1) continue;
			s[t][0] = i;
			s[t][1] = j;
		}
	}

	bool possible = false;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int t = p[i] + p[j];
			int l = w - t;
			if (l < 2) continue;
			if (l > 400'000) continue;
			if (s[l][0] == -1) continue;

			int a = s[l][0];
			int b = s[l][1];
			if (a == i || a == j) continue;
			if (b == i || b == j) continue;

			possible = true;
			break;
		}

		if (possible) break;
	}

	if (possible) cout << "YES";
	else cout << "NO";

	return 0;
}
