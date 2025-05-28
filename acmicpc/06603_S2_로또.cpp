#include <iostream>

using namespace std;

int k;
int S[16];
int arr[16];

void bkt(int p)
{
	if (p == 6)
	{
		for (int i = 0; i < 6; ++i) cout << S[arr[i]] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < k; ++i)
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

	while (true)
	{
		cin >> k;
		if (!k) break;

		for (int i = 0; i < k; ++i) cin >> S[i];

		bkt(0);
		cout << '\n';
	}

	return 0;
}
