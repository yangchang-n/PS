#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T, N, K, W;
struct Info
{
	int ind = 0;
	int tim = 0;
	int bef = 0;
} info[1010];
vector<int> edge[1010];
queue<int> que;

static void init()
{
	int D, X, Y;
	for (int i = 1; i <= N; ++i)
	{
		cin >> D;
		info[i].ind = 0;
		info[i].tim = D;
		info[i].bef = 0;
		edge[i] = vector<int>();
	}
	for (int i = 1; i <= K; ++i)
	{
		cin >> X >> Y;
		info[Y].ind++;
		edge[X].push_back(Y);
	}
	que = queue<int>();
}

static void solve()
{
	for (int i = 1; i <= N; ++i)
	{
		if (!info[i].ind) que.push(i);
	}

	while (!que.empty())
	{
		int c = que.front();
		int ct = info[c].tim + info[c].bef;
		que.pop();

		if (c == W)
		{
			cout << ct << '\n';
			break;
		}

		for (int n : edge[c])
		{
			info[n].ind--;
			info[n].bef = max(ct, info[n].bef);
			if (!info[n].ind) que.push(n);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		init();
		cin >> W;
		solve();
	}

	return 0;
}
