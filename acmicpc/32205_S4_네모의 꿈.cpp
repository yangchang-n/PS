#include <iostream>

using namespace std;

int N;
bool pre[1'000'010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (pre[a] || pre[b] || pre[c])
		{
			cout << 1;
			return 0;
		}
		else pre[a] = pre[b] = pre[c] = true;
	}

	cout << 0;

	return 0;
}
