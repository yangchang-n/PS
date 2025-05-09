#include <iostream>
#include <array>
#include <queue>

using namespace std;

int dst[1'000'010];
queue<array<int, 2>> que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; ++i)
	{
		dst[i] = -1;
	}

	int n;
	for (int i = 0; i < M; ++i)
	{
		cin >> n;

		que.push({ 0, n });
		dst[n] = 0;
	}

	while (!que.empty())
	{
		int cd = que.front()[0];
		int cn = que.front()[1];
		que.pop();

		int msk = 1;
		int nd = cd + 1;
		while (msk <= N)
		{
			int nn = (cn ^ msk);

			if (nn > N || dst[nn] > 0)
			{
				msk <<= 1;
				continue;
			}

			que.push({ nd, nn });
			dst[nn] = nd;

			msk <<= 1;
		}
	}

	int ans = 0;
	for (int i = 0; i <= N; ++i)
	{
		ans = max(ans, dst[i]);
	}

	cout << ans;

	return 0;
}
