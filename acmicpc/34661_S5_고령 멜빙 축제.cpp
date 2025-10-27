#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, n, m;
	string str;

	cin >> t;
	for (int tc = 1; tc <= t; ++tc)
	{
		cin >> n >> m;
		int total = n * m;
		for (int i = 0; i < n; ++i)
		{
			cin >> str;
			for (char c : str)
			{
				if (c == 'x') total--;
			}
		}

		if (total % 2) cout << "sewon\n";
		else cout << "pizza\n";
	}

	return 0;
}
