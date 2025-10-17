#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int R, C, T;
	cin >> R >> C;
	vector<vector<int>> img(R, vector<int>(C));
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j) cin >> img[i][j];
	}
	cin >> T;

	int ans = 0;
	for (int i = 0; i < R - 2; ++i)
	{
		for (int j = 0; j < C - 2; ++j)
		{
			vector<int> msk;
			msk.reserve(9);
			for (int p = 0; p < 3; ++p)
			{
				for (int q = 0; q < 3; ++q) msk.push_back(img[i + p][j + q]);
			}
			sort(msk.begin(), msk.end());

			if (msk[4] >= T) ans++;
		}
	}

	cout << ans;

	return 0;
}
