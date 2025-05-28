#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int L, C;
int con, vow;
char bet[16];
char arr[16];

static unordered_set<char> us = { 'a', 'e', 'i', 'o', 'u' };

void bkt(int p)
{
	if (p == L)
	{
		con = 0;
		vow = 0;

		for (int i = 0; i < L; ++i)
		{
			if (us.count(bet[arr[i]])) vow++;
			else con++;

			if (con > 1 && vow) break;
			if (i == L - 1) return;
		}

		for (int i = 0; i < L; ++i) cout << bet[arr[i]];
		cout << '\n';
		return;
	}

	for (int i = 0; i < C; ++i)
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

	cin >> L >> C;
	for (int i = 0; i < C; ++i) cin >> bet[i];
	sort(bet, bet + C);

	bkt(0);

	return 0;
}
