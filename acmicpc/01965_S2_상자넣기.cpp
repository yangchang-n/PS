#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> nm(N);
	vector<int> tb(N, 1);

	for (int i = 0; i < N; ++i) cin >> nm[i];

	for (int i = 0; i < N; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (nm[i] > nm[j] && tb[i] < tb[j] + 1)
			{
				tb[i] = tb[j] + 1;
			}
		}
	}

	cout << *max_element(tb.begin(), tb.end());

	return 0;
}
