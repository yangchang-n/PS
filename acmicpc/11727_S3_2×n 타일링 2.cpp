#include <iostream>

using namespace std;

int cnt[1'010];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	cnt[1] = 1;
	cnt[2] = 3;
	for (int i = 3; i <= N; ++i)
	{
		cnt[i] = cnt[i - 1] + cnt[i - 2] * 2;
		if (cnt[i] >= 10'007) cnt[i] %= 10'007;
	}

	cout << cnt[N];

	return 0;
}
