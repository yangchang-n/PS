#include <iostream>

using namespace std;
using ll = long long;

ll tb[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	tb[1] = 1;
	tb[2] = 1;
	for (int i = 3; i <= N; ++i)
	{
		tb[i] = 1;
		for (int j = 1; j <= i - 2; ++j) tb[i] += tb[j];
	}

	cout << tb[N];

	return 0;
}
