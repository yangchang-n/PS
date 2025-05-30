#include <iostream>

using namespace std;

int cnt[1'000'010];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	cnt[1] = 0;
	for (int i = 2; i <= N; ++i)
	{
		cnt[i] = cnt[i - 1] + 1;
		if (!(i % 2)) cnt[i] = min(cnt[i], cnt[i / 2] + 1);
		if (!(i % 3)) cnt[i] = min(cnt[i], cnt[i / 3] + 1);
	}

	cout << cnt[N];

	return 0;
}
