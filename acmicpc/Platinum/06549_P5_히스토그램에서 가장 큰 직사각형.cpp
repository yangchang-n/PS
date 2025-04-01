#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using ll = long long;

#include <iostream>
#include <array>
#include <stack>

int main()
{
	fastIO;

	while (true)
	{
		ll n, h, s, tmp, ans = 0;
		cin >> n;
		if (n == 0) return 0;

		stack<array<ll, 2>> stk;
		bool pass;

		for (ll i = 1; i <= n; ++i)
		{
			cin >> h;
			s = i;
			pass = false;

			while (!stk.empty())
			{
				if (stk.top()[0] > h)
				{
					tmp = stk.top()[0] * (i - stk.top()[1]);
					ans = max(ans, tmp);

					s = stk.top()[1];
					stk.pop();
				}
				else if (stk.top()[0] == h)
				{
					pass = true;
					break;
				}
				else break;
			}

			if (!pass) stk.push({ h, s });
		}

		while (!stk.empty())
		{
			tmp = stk.top()[0] * (n + 1 - stk.top()[1]);
			ans = max(ans, tmp);

			stk.pop();
		}

		cout << ans << '\n';
	}

	return 0;
}
