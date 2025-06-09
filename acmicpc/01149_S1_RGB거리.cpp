#include <iostream>
#include <algorithm>

using namespace std;

int tb[1010][3];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	cin >> tb[0][0] >> tb[0][1] >> tb[0][2];
	for (int i = 1; i < N; ++i)
	{
		int t0, t1, t2;
		cin >> t0 >> t1 >> t2;
		tb[i][0] = min(tb[i - 1][1], tb[i - 1][2]) + t0;
		tb[i][1] = min(tb[i - 1][0], tb[i - 1][2]) + t1;
		tb[i][2] = min(tb[i - 1][0], tb[i - 1][1]) + t2;
	}

	cout << min({ tb[N - 1][0], tb[N - 1][1], tb[N - 1][2] });

	return 0;
}
