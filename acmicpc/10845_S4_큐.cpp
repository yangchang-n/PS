#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
// using ll = long long;

#include <iostream>

int que[10'000];
int fnt = 0, bck = 0;

int main()
{
	fastIO;

	int N, num;
	string opt;

	cin >> N;

	for (int q = 0; q < N; ++q)
	{
		cin >> opt;

		if (opt == "push")
		{
			cin >> num;
			que[bck++] = num;
		}
		else if (opt == "pop")
		{
			if (fnt == bck) cout << -1 << '\n';
			else cout << que[fnt++] << '\n';
		}
		else if (opt == "size")
		{
			cout << bck - fnt << '\n';
		}
		else if (opt == "empty")
		{
			if (fnt == bck) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (opt == "front")
		{
			if (fnt == bck) cout << -1 << '\n';
			else cout << que[fnt] << '\n';
		}
		else if (opt == "back")
		{
			if (fnt == bck) cout << -1 << '\n';
			else cout << que[bck - 1] << '\n';
		}
	}

	return 0;
}
