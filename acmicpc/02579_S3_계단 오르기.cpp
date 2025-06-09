#include <iostream>

using namespace std;

int st[310];
int mx[310][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> st[i];

	mx[1][0] = st[1];
	mx[1][1] = 0;
	mx[2][0] = st[2];
	mx[2][1] = st[1] + st[2];

	for (int i = 3; i <= N; ++i)
	{
		mx[i][0] = max(mx[i - 2][0], mx[i - 2][1]) + st[i];
		mx[i][1] = mx[i - 1][0] + st[i];
	}

	cout << max(mx[N][0], mx[N][1]);

	return 0;
}
