#include <iostream>
#include <set>

using namespace std;

multiset<int> ms;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		ms.clear();

		int k, n;
		char opt;
		cin >> k;

		for (int i = 0; i < k; ++i)
		{
			cin >> opt >> n;

			if (opt == 'I') ms.insert(n);
			else if (!ms.empty())
			{
				if (n == 1)
				{
					auto it = prev(ms.end());
					ms.erase(it);
				}
				else ms.erase(ms.begin());
			}
		}

		if (ms.empty()) cout << "EMPTY\n";
		else cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
	}

	return 0;
}
