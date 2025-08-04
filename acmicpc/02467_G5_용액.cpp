#include <iostream>
#include <cmath>

using namespace std;

int N;
int ph[100'010];
int ans[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> ph[i];

	int s = 0;
	int e = N - 1;

	if (ph[s] > 0)
	{
		cout << ph[s] << ' ' << ph[s + 1];
		return 0;
	}

	if (ph[e] < 0)
	{
		cout << ph[e - 1] << ' ' << ph[e];
		return 0;
	}

	int sm = ph[s] + ph[e];
	int pr = 2'000'000'010;

	while (s < e)
	{
		sm = ph[s] + ph[e];

		if (abs(sm) <= pr)
		{
			pr = abs(sm);
			ans[0] = ph[s];
			ans[1] = ph[e];
		}

		if (sm == 0) break;
		else if (sm < 0) s++;
		else if (sm > 0) e--;
	}

	cout << ans[0] << ' ' << ans[1];

	return 0;
}
