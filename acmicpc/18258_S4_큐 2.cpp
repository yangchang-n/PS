#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
// using ll = long long;

#include <iostream>

int que[2'000'000];
int fnt = 0, bck = 0;

int main()
{
	fastIO;

	int N, num;
	char opt[10];

	cin >> N;

	for (int q = 0; q < N; ++q)
	{
		cin >> opt;

		if (opt[0] == 'p')
		{
			if (opt[1] == 'u')
			{
				cin >> num;
				que[bck++] = num;
			}
			else
			{
				if (fnt == bck) cout << -1 << '\n';
				else cout << que[fnt++] << '\n';
			}
		}
		else if (opt[0] == 's')
		{
			cout << bck - fnt << '\n';
		}
		else if (opt[0] == 'e')
		{
			if (fnt == bck) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (opt[0] == 'f')
		{
			if (fnt == bck) cout << -1 << '\n';
			else cout << que[fnt] << '\n';
		}
		else
		{
			if (fnt == bck) cout << -1 << '\n';
			else cout << que[bck - 1] << '\n';
		}
	}

	return 0;
}
