#include <iostream>
#include <queue>

using namespace std;

queue<int> que;
int dst[100010];
int way[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	fill(dst, dst + 100010, -1);
	// fill(way, way + 100010, 0);

	que.push(N);
	dst[N] = 0;
	way[N] = 1;

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		for (int c : { cur * 2, cur + 1, cur - 1 })
		{
			if (c < 0 || c > 100000) continue;

			if (dst[c] == -1)
			{
				que.push(c);
				dst[c] = dst[cur] + 1;
				way[c] = way[cur];
			}
			else if (dst[c] == dst[cur] + 1)
			{
				way[c] += way[cur];
			}
		}
	}

	cout << dst[K] << '\n' << way[K];

	return 0;
}
