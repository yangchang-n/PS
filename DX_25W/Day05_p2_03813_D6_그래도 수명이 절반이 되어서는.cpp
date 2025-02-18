#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

// start

#include <iostream>

using namespace std;

int N, K;
int W[200'000];
int S[200'000];

bool is_possible(int m)
{
	int idx = 0, temp = 0;

	for (int i = 0; i < N; ++i)
	{
		if (W[i] > m)
		{
			temp = 0;
			continue;
		}

		temp++;

		if (temp == S[idx])
		{
			idx++;
			temp = 0;
		}
		if (idx == K) return true;
	}

	return false;
}

int bin_search()
{
	int l = 1, r = 200'000, m, val;
	bool possible = false;

	while (l <= r)
	{
		m = l + (r - l) / 2;

		possible = is_possible(m);

		if (possible)
		{
			val = m;
			r = m - 1;
		}
		else l = m + 1;
	}

	return val;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("sample_input.txt", "r", stdin); // have to erase

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;

		for (int i = 0; i < N; ++i) cin >> W[i];
		for (int i = 0; i < K; ++i) cin >> S[i];

		int ans = bin_search();

		cout << '#' << test_case << ' ' << ans << '\n';
	}

	return 0;
}
