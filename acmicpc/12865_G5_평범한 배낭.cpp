#include <iostream>

using namespace std;

int tb[110][100010];
int w[110];
int v[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) cin >> w[i] >> v[i];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			if (i)
			{
				if (j < w[i]) tb[i][j] = tb[i - 1][j];
				else tb[i][j] = max(tb[i - 1][j], tb[i - 1][j - w[i]] + v[i]);
			}
			else if (j >= w[i]) tb[i][j] = v[i];
		}
	}

	cout << tb[N - 1][K];

	return 0;
}
