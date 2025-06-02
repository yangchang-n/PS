#include <iostream>

using namespace std;

int num[500][500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j) cin >> num[i][j];
	}

	for (int i = n - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			num[i - 1][j] += max(num[i][j], num[i][j + 1]);
		}
	}

	cout << num[0][0];

	return 0;
}
