#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using ll = long long;

#include <iostream>

ll stk[100'000][2];
int pos;

int main()
{
	fastIO;

	while (true)
	{
		ll n, h, s, tmp, ans = 0;
		cin >> n;
		if (n == 0) return 0;

		pos = 0;
		bool pass;

		for (ll i = 0; i < n; ++i)
		{
			cin >> h;
			s = i;
			pass = false;

			while (pos)
			{
				if (stk[pos - 1][0] > h)
				{
					tmp = stk[pos - 1][0] * (i - stk[pos - 1][1]);
					ans = max(ans, tmp);
					s = stk[--pos][1];
				}
				else if (stk[pos - 1][0] == h)
				{
					pass = true;
					break;
				}
				else break;
			}

			if (!pass)
			{
				stk[pos][0] = h;
				stk[pos][1] = s;
				pos++;
			}
		}

		while (pos)
		{
			tmp = stk[pos - 1][0] * (n - stk[pos - 1][1]);
			ans = max(ans, tmp);
			pos--;
		}

		cout << ans << '\n';
	}

	return 0;
}
