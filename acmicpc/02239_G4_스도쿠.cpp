#include <iostream>

using namespace std;

int bd[9][9];
bool rw[9][10] = {};
bool cn[9][10] = {};
bool bx[9][10] = {};
bool done = false;

void bkt(int i, int j)
{
	if (i >= 9)
	{
		done = true;
		return;
	}

	int ni = i;
	int nj = j + 1;
	if (nj >= 9)
	{
		ni = i + 1;
		nj = 0;
	}

	if (bd[i][j])
	{
		bkt(ni, nj);
		return;
	}

	for (int n = 1; n <= 9; ++n)
	{
		if (rw[i][n]) continue;
		if (cn[j][n]) continue;

		int bx_num = (i / 3) * 3 + (j / 3);
		if (bx[bx_num][n]) continue;

		bd[i][j] = n;
		rw[i][n] = true;
		cn[j][n] = true;
		bx[bx_num][n] = true;

		bkt(ni, nj);
		if (done) return;

		bd[i][j] = 0;
		rw[i][n] = false;
		cn[j][n] = false;
		bx[bx_num][n] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 9; ++i)
	{
		string line;
		cin >> line;

		for (int j = 0; j < 9; ++j)
		{
			int n = line[j] - '0';
			bd[i][j] = n;

			if (n)
			{
				rw[i][n] = true;
				cn[j][n] = true;

				int bx_num = (i / 3) * 3 + (j / 3);
				bx[bx_num][n] = true;
			}
		}
	}

	bkt(0, 0);

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j) cout << bd[i][j];
		cout << '\n';
	}

	return 0;
}
