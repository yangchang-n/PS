#include <iostream>
#include <algorithm>

int N;
int cnt[55];
bool f1[55][55];
bool f2[55][55];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < N; ++j)
		{
			if (str[j] == 'Y') f1[i][j] = f2[i][j] = 1;
		}
	}

	for (int m = 0; m < N; ++m)
	{
		for (int s = 0; s < N; ++s)
		{
			for (int e = 0; e < N; ++e)
			{
				if (s == m || m == e || s == e) continue;
				if (f2[s][e]) continue;
				if (f1[s][m] && f1[m][e]) f2[s][e] = 1;
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (f2[i][j]) cnt[i]++;
		}
	}

	int ans = *std::max_element(cnt, cnt + N);
	std::cout << ans;

	return 0;
}
