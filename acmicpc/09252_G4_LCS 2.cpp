#include <iostream>

using namespace std;

int lcs[1010][1010][3];
char stk[1010];
int pos = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string A, B;
	cin >> A >> B;

	int asz = A.size();
	int bsz = B.size();

	for (int i = 0; i < asz; ++i)
	{
		for (int j = 0; j < bsz; ++j)
		{
			if (A[i] == B[j])
			{
				lcs[i + 1][j + 1][0] = lcs[i][j][0] + 1;
				lcs[i + 1][j + 1][1] = i;
				lcs[i + 1][j + 1][2] = j;
			}
			else
			{
				if (lcs[i][j + 1][0] >= lcs[i + 1][j][0])
				{
					lcs[i + 1][j + 1][0] = lcs[i][j + 1][0];
					lcs[i + 1][j + 1][1] = i;
					lcs[i + 1][j + 1][2] = j + 1;
				}
				else
				{
					lcs[i + 1][j + 1][0] = lcs[i + 1][j][0];
					lcs[i + 1][j + 1][1] = i + 1;
					lcs[i + 1][j + 1][2] = j;
				}
			}
		}
	}

	cout << lcs[asz][bsz][0] << '\n';

	int ti = asz;
	int tj = bsz;

	while (ti && tj)
	{
		int pi = lcs[ti][tj][1];
		int pj = lcs[ti][tj][2];

		if (ti == pi + 1 && tj == pj + 1 && A[ti - 1] == B[tj - 1])
		{
			stk[pos++] = A[ti - 1];
		}

		ti = pi;
		tj = pj;
	}

	while (pos) cout << stk[--pos];

	return 0;
}
