#include <iostream>
#include <queue>

using namespace std;

bool num[2'000'010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, tmp;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		num[tmp + 1'000'000] = true;
	}

	for (int i = 0; i <= 2'000'000; ++i)
	{
		if (num[i])
		{
			cout << i - 1'000'000 << '\n';
		}
	}

	return 0;
}
