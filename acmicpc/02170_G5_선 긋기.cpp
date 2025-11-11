#include <iostream>
#include <algorithm>
#include <array>

using namespace std;
using ai2 = array<int, 2>;

ai2 line[1'000'010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> line[i][0] >> line[i][1];
	sort(line, line + N);

	int ans = 0;
	int s = line[0][0];
	int e = line[0][1];
	for (int i = 1; i < N; ++i)
	{
		if (line[i][0] > e)
		{
			ans += e - s;
			s = line[i][0];
		}
		if (line[i][1] > e)
		{
			e = line[i][1];
		}
	}
	ans += e - s;

	cout << ans;

	return 0;
}
