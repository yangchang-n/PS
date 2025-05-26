#include <iostream>

using namespace std;

int N, M;
int arr[10];

void bkt(int p)
{
	if (p == M)
	{
		for (int i = 0; i < M; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		arr[p] = i;
		bkt(p + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	bkt(0);

	return 0;
}
