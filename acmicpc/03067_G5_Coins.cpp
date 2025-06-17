#include <iostream>

using namespace std;

int c[32];
int tb[32][10010];

void dp(int N, int M)
{
	for (int i = 0; i < N; ++i)
	{
		tb[i][0] = 1;
		for (int j = 1; j <= M; ++j)
		{
			tb[i][j] = 0;
			if (i) tb[i][j] += tb[i - 1][j];
			if (j - c[i] >= 0) tb[i][j] += tb[i][j - c[i]];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N, M;
		cin >> N;
		for (int i = 0; i < N; ++i) cin >> c[i];
		cin >> M;

		dp(N, M);

		cout << tb[N - 1][M] << '\n';
	}

	return 0;
}
