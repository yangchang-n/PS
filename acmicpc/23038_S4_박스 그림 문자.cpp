#include <iostream>

using namespace std;

char bd[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N * 3; ++i)
	{
		string line;
		cin >> line;
		for (int j = 0; j < M * 3; ++j) bd[i][j] = line[j];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int ci = i * 3 + 1;
			int cj = j * 3 + 1;

			if (bd[ci][cj] != '.') continue;

			bd[ci][cj] = '#';
			if (i && bd[ci - 2][cj] == '#') bd[ci - 1][cj] = '#';
			if (j && bd[ci][cj - 2] == '#') bd[ci][cj - 1] = '#';
			if (i != N - 1 && bd[ci + 2][cj] == '#') bd[ci + 1][cj] = '#';
			if (j != M - 1 && bd[ci][cj + 2] == '#') bd[ci][cj + 1] = '#';
		}
	}

	for (int i = 0; i < N * 3; ++i)
	{
		for (int j = 0; j < M * 3; ++j) cout << bd[i][j];
		cout << '\n';
	}

	return 0;
}
