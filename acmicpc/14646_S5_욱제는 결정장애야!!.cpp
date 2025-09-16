#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int cnt = 0;
	int ans = 0;
	vector<bool> sti(N + 1, false);

	for (int i = 0; i < N * 2; ++i)
	{
		int tmp;
		cin >> tmp;

		if (sti[tmp]) cnt--;
		else
		{
			sti[tmp] = true;
			cnt++;
			ans = max(ans, cnt);
		}
	}

	cout << ans;

	return 0;
}
