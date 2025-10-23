#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int sz = 1 << N;

	for (int r = 0; r < sz; ++r)
	{
		for (int c = 0; c < sz; ++c)
		{
			if (c == sz - r) break;
			if (r & c) cout << ' ';
			else cout << '*';
		}
		if (r < sz - 1) cout << '\n';
	}

	return 0;
}
