#include <iostream>

using namespace std;

int N, M;
int num[2010];
bool pal[2010][2010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> num[i];

	pal[1][1] = true;
	pal[2][2] = true;
	if (num[1] == num[2]) pal[1][2] = true;
	for (int i = 3; i <= N; ++i)
	{
		pal[i][i] = true;
		if (num[i - 1] == num[i]) pal[i - 1][i] = true;
		if (num[i - 2] == num[i]) pal[i - 2][i] = true;
	}

	for (int p = 4; p <= N; ++p)
	{
		for (int i = p; i <= N; ++i)
		{
			if (num[i - p + 1] != num[i]) continue;
			if (!pal[i - p + 2][i - 1]) continue;
			pal[i - p + 1][i] = true;
		}
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int S, E;
		cin >> S >> E;

		if (pal[S][E]) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}
