#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using ll = long long;

#include <iostream>

int bd[80'000][2];
int pos = 0;

int main()
{
	fastIO;

	int N, h;
	ll ans = 0;

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> h;

		while (pos)
		{
			if (bd[pos - 1][0] <= h)
			{
				ans += i - bd[pos - 1][1] - 1;
				pos--;
			}
			else break;
		}

		bd[pos][0] = h;
		bd[pos][1] = i;
		pos++;
	}

	while (pos)
	{
		ans += N - bd[pos - 1][1];
		pos--;
	}

	cout << ans;

	return 0;
}
