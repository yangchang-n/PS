#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int n;
		cin >> n;

		unordered_map<string, int> um;
		for (int i = 0; i < n; ++i)
		{
			string clo, typ;
			cin >> clo >> typ;

			if (um.count(typ)) um[typ]++;
			else um[typ] = 1;
		}

		int ans = 1;
		if (!um.empty())
		{
			for (auto p : um) ans *= p.second + 1;
		}

		cout << ans - 1 << '\n';
	}

	return 0;
}
