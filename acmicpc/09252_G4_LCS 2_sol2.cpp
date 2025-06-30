#include <iostream>

using namespace std;

int lcs[1010][1010];
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
			if (A[i] == B[j]) lcs[i + 1][j + 1] = lcs[i][j] + 1;
			else
			{
				if (lcs[i][j + 1] >= lcs[i + 1][j])
				{
					lcs[i + 1][j + 1] = lcs[i][j + 1];
				}
				else
				{
					lcs[i + 1][j + 1] = lcs[i + 1][j];
				}
			}
		}
	}

	cout << lcs[asz][bsz] << '\n';

	int ti = asz;
	int tj = bsz;

	while (ti && tj)
	{
		if (A[ti - 1] == B[tj - 1])
		{
			stk[pos++] = A[ti - 1];
			ti--;
			tj--;
		}
		else if (lcs[ti][tj] == lcs[ti - 1][tj])
		{
			ti--;
		}
		else
		{
			tj--;
		}
	}

	while (pos) cout << stk[--pos];

	return 0;
}
