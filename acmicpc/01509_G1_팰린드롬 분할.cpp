#include <iostream>

using namespace std;

string str;
int sz = 0;
int cnt[2510];
bool pal[2510][2510];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str;
	sz = str.size();

	pal[0][0] = true;
	pal[1][1] = true;
	if (str[0] == str[1]) pal[0][1] = true;
	for (int i = 2; i < sz; ++i)
	{
		pal[i][i] = true;
		if (str[i - 1] == str[i]) pal[i - 1][i] = true;
		if (str[i - 2] == str[i]) pal[i - 2][i] = true;
	}

	for (int p = 4; p <= sz; ++p)
	{
		for (int i = p - 1; i < sz; ++i)
		{
			if (str[i - p + 1] != str[i]) continue;
			if (!pal[i - p + 2][i - 1]) continue;
			pal[i - p + 1][i] = true;
		}
	}

	cnt[0] = 0;
	cnt[1] = 1;
	for (int p = 2; p <= sz; ++p)
	{
		int tmp = 2510;
		for (int i = 0; i < p; ++i)
		{
			if (pal[i][p - 1]) tmp = min(tmp, cnt[i] + 1);
		}
		cnt[p] = tmp;
	}

	cout << cnt[sz];

	return 0;
}
