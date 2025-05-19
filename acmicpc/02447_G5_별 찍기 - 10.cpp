#include <iostream>
#include <vector>

using namespace std;

void star_rec(vector<vector<char>>& v, int N, int si, int sj)
{
	if (N == 1)
	{
		v[si][sj] = '*';
		return;
	}

	int T = N / 3;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == 1 && j == 1) continue;
			star_rec(v, T, si + i * T, sj + j * T);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<char>> v(N, vector<char>(N, ' '));

	star_rec(v, N, 0, 0);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j) cout << v[i][j];
		cout << '\n';
	}

	return 0;
}
