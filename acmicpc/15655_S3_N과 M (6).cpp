#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int num[10];
int arr[10];

void bkt(int p)
{
	if (p == M)
	{
		for (int i = 0; i < M; ++i) cout << num[arr[i]] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (p && arr[p - 1] >= i) continue;

		arr[p] = i;
		bkt(p + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> num[i];
	sort(num, num + N);

	bkt(0);

	return 0;
}
