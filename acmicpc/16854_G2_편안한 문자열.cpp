#include <iostream>
#include <string>

using namespace std;

string str;
bool sym[5010][5010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str;
	int sz = str.size();

	for (int i = 0; i < sz - 1; ++i)
	{
		int s = i;
		int e = i + 1;
		while (0 <= s && e < sz)
		{
			if (str[s] == str[e]) break;
			sym[s][e] = true;
			s--; e++;
		}
	}

	int ans = 0;
	for (int s = 0; s < sz - 1; ++s)
	{
		int n = 0;
		for (int e = s; e < sz; ++e)
		{
			if (str[e] == '(') n++;
			else n--;
			if (n < 0) break;
			if (n) continue;
			if (sym[s][e]) ans++;
		}
	}

	cout << ans;

	return 0;
}
