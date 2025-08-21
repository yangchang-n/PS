#include <iostream>
#include <algorithm>

using namespace std;

int N;
int rp[100'0010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> rp[i];
	sort(rp, rp + N);

	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		ans = max(ans, rp[i] * (N - i));
	}

	cout << ans;

	return 0;
}
