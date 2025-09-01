#include <iostream>
#include <cmath>

using namespace std;

int N, cnt = 1;
int pri[500'000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	pri[0] = 2;
	cin >> N;

	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	for (int n = 3; n <= N; n += 2)
	{
		bool possible = true;
		int sqrtn = sqrt(n);

		for (int i = 0; i < cnt; ++i)
		{
			if (pri[i] > sqrtn) break;
			if (!(n % pri[i]))
			{
				possible = false;
				break;
			}
		}

		if (possible) pri[cnt++] = n;
	}

	int ans = 0;
	int sum = 0;
	int s = 0, e = 0;
	while (true)
	{
		if (sum <= N)
		{
			if (sum == N) ans++;
			if (e == cnt) break;
			sum += pri[e++];
		}
		else sum -= pri[s++];
	}

	cout << ans;

	return 0;
}
