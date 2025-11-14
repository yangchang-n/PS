#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;
	int sz = str.size();

	int cnt[26] = {};
	for (char c : str) cnt[c - 'a']++;

	int pr = sz / 2;
	int od = sz % 2;
	for (int i = 0; i < 26; ++i)
	{
		if (cnt[i] > pr + od)
		{
			cout << "-1";
			return 0;
		}
	}

	string ans(sz, '?');
	for (int i = 0; i < pr; ++i)
	{
		int j = sz - i - 1;
		int r = pr - i - 1;
		bool done = false;

		for (int a = 0; a < 26; ++a)
		{
			if (done) break;
			if (!cnt[a]) continue;
			cnt[a]--;

			for (int b = 25; b >= 0; --b)
			{
				if (done) break;
                if (b == a) break;
				if (!cnt[b]) continue;
				cnt[b]--;

				bool possible = true;
				for (int k = 0; k < 26; ++k)
				{
					if (cnt[k] > r + od)
					{
						possible = false;
						break;
					}
				}

				if (possible)
				{
					ans[i] = char(a + 'a');
					ans[j] = char(b + 'a');
					done = true;
				}
				else cnt[b]++;
			}

			if (!done) cnt[a]++;
		}

		if (!done)
		{
			cout << "-1";
			return 0;
		}
	}

	if (od)
	{
		for (int k = 0; k < 26; ++k)
		{
			if (cnt[k]) ans[pr] = char(k + 'a');
		}
	}

	cout << ans;

	return 0;
}
