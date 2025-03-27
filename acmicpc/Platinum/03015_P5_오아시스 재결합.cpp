#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using ll = long long;

#include <iostream>

struct Group
{
	ll h;
	int p;
} stk[500'000];
int pos = 0;

int main()
{
	fastIO;

	int N, cnt;
	ll ht, ans = 0;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> ht;
		cnt = 1;

		while (pos)
		{
			if (stk[pos - 1].h < ht) ans += stk[--pos].p;
			else if (stk[pos - 1].h == ht)
			{
				auto tmp = stk[--pos];

				if (pos) ans++;
				ans += tmp.p;
				cnt += tmp.p;

				break;
			}
			else
			{
				ans++;
				break;
			}
		}

		stk[pos++] = { ht, cnt };
	}

	cout << ans;

	return 0;
}
