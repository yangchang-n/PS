#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int Q, M;
	cin >> Q;
	while (Q--)
	{
		cin >> M;
		int cnt = M / 50;
		int tim = 6;
		tim += 12 * cnt;

		int h = tim / 60 + 6;
		int m = tim % 60;

		if (h >= 24)
		{
			cout << "-1\n";
			continue;
		}

		if (h < 10) cout << '0';
		cout << h << ':';
		if (m < 10) cout << '0';
		cout << m << '\n';
	}

	return 0;
}
