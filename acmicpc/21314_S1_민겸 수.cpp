#include <iostream>

using namespace std;

char mx[3010];
char mn[3010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string str;
	cin >> str;
	int sz = str.size();

	int lm = -1;
	bool bk = true;
	for (int i = 0; i < sz; ++i)
	{
		char c = str[i];

		if (c == 'M')
		{
			if (bk)
			{
				lm = i;
				mx[i] = mn[i] = '1';
			}
			else mx[i] = mn[i] = '0';
			bk = false;
		}
		else
		{
			if (bk) mx[i] = mn[i] = '5';
			else
			{
				mx[i] = '0';
				mn[i] = '5';
				if (lm >= 0)
				{
					mx[lm] = '5';
					mn[lm] = '1';
					lm = -1;
				}
			}
			bk = true;
		}
	}

	for (int i = sz - 1; i > 0; --i)
	{
		if (str[i] == 'K') break;
		mx[i] = '1';
	}

	for (int i = 0; i < sz; ++i) cout << mx[i];
	cout << '\n';
	for (int i = 0; i < sz; ++i) cout << mn[i];

	return 0;
}
