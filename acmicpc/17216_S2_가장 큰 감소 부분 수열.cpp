#include <iostream>
#include <algorithm>

using namespace std;

int n[1010];
int s[1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, t;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> t;
		n[i] = s[i] = t;
	}

	if (N == 1)
	{
		cout << n[0];
		return 0;
	}

	for (int i = N - 2; i >= 0; --i)
	{
		int tmp = 0;
		for (int j = i + 1; j < N; ++j)
		{
			if (n[i] <= n[j]) continue;
			if (tmp >= s[j]) continue;
			tmp = s[j];
		}
		s[i] += tmp;
	}

	cout << *max_element(s, s + N);

	return 0;
}
