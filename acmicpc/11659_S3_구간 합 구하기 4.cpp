#include <iostream>

using namespace std;

int sum[100'010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, tmp, tot = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> tmp;
		tot += tmp;
		sum[i] = tot;
	}

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}

	return 0;
}
