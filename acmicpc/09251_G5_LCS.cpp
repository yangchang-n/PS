#include <iostream>
#include <algorithm>

using namespace std;

int tb[1010][1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string A, B;
	cin >> A >> B;

	int asz = A.size(), bsz = B.size();
	for (int i = 0; i <= asz; ++i) tb[i][0] = 0;
	for (int i = 0; i <= bsz; ++i) tb[0][i] = 0;

	for (int i = 0; i < asz; ++i)
	{
		for (int j = 0; j < bsz; ++j)
		{
			if (A[i] != B[j]) tb[i + 1][j + 1] = max(tb[i + 1][j], tb[i][j + 1]);
			else tb[i + 1][j + 1] = max({ tb[i][j] + 1, tb[i + 1][j], tb[i][j + 1] });
		}
	}

	cout << tb[asz][bsz];

	return 0;
}
