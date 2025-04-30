#include <iostream>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, num;
	cin >> M;

	ll num_set = 0;

	for (int i = 0; i < M; ++i)
	{
		string opt;
		cin >> opt;

		if (opt[1] == 'd')
		{
			cin >> num;
			num_set |= (1LL << (num - 1));
		}
		else if (opt[1] == 'e')
		{
			cin >> num;
			num_set &= ~(1LL << (num - 1));
		}
		else if (opt[1] == 'h')
		{
			cin >> num;
			cout << ((num_set & (1LL << (num - 1))) ? 1 : 0) << '\n';
		}
		else if (opt[1] == 'o')
		{
			cin >> num;
			num_set ^= (1LL << (num - 1));
		}
		else if (opt[1] == 'l') num_set = (1LL << 20) - 1;
		else if (opt[1] == 'm') num_set = 0;
	}

	return 0;
}
