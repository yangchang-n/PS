#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int N;
ll num[100'010];
ll S, tm, sm = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S;
	for (int i = 1; i <= N; ++i)
	{
		cin >> tm;
		sm += tm;
		num[i] = sm;
	}

	int s = 0;
	int e = 1;
	int ans = 100'010;
	ll pre = 0;

	while (e <= N)
	{
		ll tmp = num[e] - num[s];

		if (tmp >= S)
		{
			if (e - s == 1)
			{
				ans = 1;
				break;
			}
			else s++;
		}
		else
		{
			if (pre >= S) ans = min(ans, e - s + 1);
			else e++;
		}

		pre = tmp;
	}

	if (ans == 100'010) cout << 0;
	else cout << ans;

	return 0;
}
