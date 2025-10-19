#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n)
	{
		int rep = 1;
		int cnt = 1;

		while (rep % n)
		{
			cnt++;
			rep = (rep * 10) % n + 1 % n;
		}

		cout << cnt << '\n';
	}

	return 0;
}
