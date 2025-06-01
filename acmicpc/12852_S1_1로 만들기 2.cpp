#include <iostream>

using namespace std;

int cnt[1'000'010];
int pre[1'000'010];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int tmp = 0;
	cnt[1] = pre[1] = 0;
	for (int i = 2; i <= N; ++i)
	{
		cnt[i] = cnt[i - 1] + 1;
		tmp = i - 1;
		if (!(i % 2) && (cnt[i] > cnt[i / 2] + 1))
		{
			cnt[i] = cnt[i / 2] + 1;
			tmp = i / 2;
		}
		if (!(i % 3) && (cnt[i] > cnt[i / 3] + 1))
		{
			cnt[i] = cnt[i / 3] + 1;
			tmp = i / 3;
		}

		pre[i] = tmp;
	}

	cout << cnt[N] << '\n';
	int nxt = N;
	while (nxt)
	{
		cout << nxt << ' ';
		nxt = pre[nxt];
	}

	return 0;
}
