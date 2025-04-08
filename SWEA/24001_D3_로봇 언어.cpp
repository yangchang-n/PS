#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

#include <iostream>

int main()
{
	fastIO;

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		string opt;
		cin >> opt;

		int seq = 0, ans = 0;
		int left_only = 0, right_only = 0;

		while (opt[seq])
		{
			if (opt[seq] == '?')
			{
				left_only++;
				right_only++;
			}
			else if (opt[seq] == 'L')
			{
				left_only++;
				right_only--;
			}
			else
			{
				left_only--;
				right_only++;
			}

			ans = max(ans, left_only);
			ans = max(ans, right_only);

			seq++;
		}

		cout << ans << '\n';
	}

	return 0;
}
