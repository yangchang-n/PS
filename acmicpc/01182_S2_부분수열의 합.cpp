#include <iostream>

using namespace std;

int N, S;
int num[32];
int cnt = 0;

void bkt(int cur, int tot)
{
	if (cur == N)
	{
		if (tot == S) cnt++;
		return;
	}

	bkt(cur + 1, tot);
	bkt(cur + 1, tot + num[cur]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S;
	for (int i = 0; i < N; ++i) cin >> num[i];

	bkt(0, 0);
	if (!S) cnt--;

	cout << cnt;

	return 0;
}
