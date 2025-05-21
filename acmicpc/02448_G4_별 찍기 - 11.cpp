#include <iostream>

using namespace std;

char stars[1 << 12][1 << 13];

void star_rec(int N, int si, int sj)
{
	if (N == 3)
	{
		stars[si][sj + 2] = '*';
		stars[si + 1][sj + 1] = '*';
		stars[si + 1][sj + 3] = '*';
		for (int j = sj; j <= sj + 4; ++j) stars[si + 2][j] = '*';
		return;
	}

	int M = N >> 1;

	star_rec(M, si, sj + M);
	star_rec(M, si + M, sj);
	star_rec(M, si + M, sj + N);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < ((N << 1) | 1); ++j) stars[i][j] = ' ';
	}

	star_rec(N, 0, 0);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < ((N << 1) | 1); ++j) cout << stars[i][j];
		cout << '\n';
	}

	return 0;
}
