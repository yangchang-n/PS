#include <iostream>

using namespace std;

int pow_2(int n)
{
	int res = 1, a = 2;

	while (n > 0)
	{
		if (n & 1) res *= a;
		a *= a;
		n >>= 1;
	}

	return res;
}

void cout_hanoi(int n, int s, int e)
{
	int m = 6 - s - e;
	if (n > 1) cout_hanoi(n - 1, s, m);
	cout << s << ' ' << e << '\n';
	if (n > 1) cout_hanoi(n - 1, m, e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	cout << pow_2(N) - 1 << '\n';
	cout_hanoi(N, 1, 3);

	return 0;
}
