#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, N;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		N %= 28;
		if (N > 15) N = 30 - N;
		else if (!N) N = 2;

		int bi[4] = {};

		for (int i = 3; i >= 0; --i)
		{
			bi[i] = N % 2;
			N /= 2;
		}

		for (int i = 0; i < 4; ++i)
		{
			if (bi[i]) cout << "딸기";
			else cout << 'V';
		}

		cout << '\n';
	}

	return 0;
}
