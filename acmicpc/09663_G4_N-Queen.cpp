#include <iostream>

using namespace std;

int N;
int cnt = 0;

bool vertical[16] = {};
bool diago_up[32] = {};
bool diago_dn[32] = {};

void bkt(int j)
{
	if (j == N)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (vertical[i] || diago_up[i + j] || diago_dn[j - i + N - 1]) continue;

		vertical[i] = diago_up[i + j] = diago_dn[j - i + N - 1] = true;
		bkt(j + 1);
		vertical[i] = diago_up[i + j] = diago_dn[j - i + N - 1] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	bkt(0);

	cout << cnt;

	return 0;
}
