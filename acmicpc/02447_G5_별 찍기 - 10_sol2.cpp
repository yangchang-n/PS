#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<char>> v(N, vector<char>(N, '*'));

	int T = N;
	while (T > 1)
	{
		for (int ti = T / 3; ti < N; ti += T)
		{
			for (int tj = T / 3; tj < N; tj += T)
			{
				for (int i = ti; i < ti + T / 3; ++i)
				{
					for (int j = tj; j < tj + T / 3; ++j) v[i][j] = ' ';
				}
			}
		}

		T /= 3;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j) cout << v[i][j];
		cout << '\n';
	}

	return 0;
}
