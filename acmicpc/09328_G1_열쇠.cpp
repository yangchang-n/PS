#include <iostream>
#include <array>
#include <queue>

using namespace std;

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };

int T, h, w, ans;
char map[100][100];
bool vis[100][100];
bool key[26];
string init_key;
queue<array<int, 2>> dr[26]; // door
queue<array<int, 2>> sp; // search_point

void key_check()
{
	for (int i = 0; i < 26; ++i)
	{
		if (!key[i]) continue;

		while (!dr[i].empty())
		{
			array<int, 2> dp = dr[i].front();
			dr[i].pop();

			sp.push(dp);
			vis[dp[0]][dp[1]] = true;
		}
	}
}

void init()
{
	ans = 0;
	for (int i = 0; i < 26; ++i) key[i] = false;
	for (int i = 0; i < 26; ++i) dr[i] = queue<array<int, 2>>();
	sp = queue<array<int, 2>>();

	cin >> h >> w;
	for (int i = 0; i < h; ++i)
	{
		string line;
		cin >> line;
		for (int j = 0; j < w; ++j)
		{
			map[i][j] = line[j];
			vis[i][j] = false;
		}
	}

	cin >> init_key;
	if (init_key != "0")
	{
		for (char c : init_key) key[c - 'a'] = true;
	}

	for (int i : { 0, h - 1 })
	{
		for (int j = 0; j < w; ++j)
		{
			char m;
			m = map[i][j];

			if (m == '*') continue;
			if ('A' <= m && m <= 'Z')
			{
				dr[m - 'A'].push({ i, j });
				continue;
			}

			if ('a' <= m && m <= 'z') key[m - 'a'] = true;
			if (m == '$') ans++;

			sp.push({ i, j });
			vis[i][j] = true;
		}
	}

	for (int i = 1; i < h - 1; ++i)
	{
		for (int j : { 0, w - 1 })
		{
			char m;
			m = map[i][j];

			if (m == '*') continue;
			if ('A' <= m && m <= 'Z')
			{
				dr[m - 'A'].push({ i, j });
				continue;
			}

			if ('a' <= m && m <= 'z') key[m - 'a'] = true;
			if (m == '$') ans++;

			sp.push({ i, j });
			vis[i][j] = true;
		}
	}

	key_check();
}

void bfs(array<int, 2> p)
{
	int i = p[0];
	int j = p[1];

	queue<array<int, 2>> que;
	que.push({ i, j });
	vis[i][j] = true;

	while (!que.empty())
	{
		array<int, 2> cur = que.front();
		int ci = cur[0];
		int cj = cur[1];
		que.pop();

		for (int d = 0; d < 4; ++d)
		{
			int ni = ci + di[d];
			int nj = cj + dj[d];

			if (ni < 0 || ni >= h) continue;
			if (nj < 0 || nj >= w) continue;
			if (vis[ni][nj]) continue;

			char m;
			m = map[ni][nj];

			if (m == '*') continue;
			if ('A' <= m && m <= 'Z')
			{
				char k = m + 32;
				if (!key[k - 'a'])
				{
					dr[m - 'A'].push({ ni, nj });
					continue;
				}
			}

			if ('a' <= m && m <= 'z') key[m - 'a'] = true;
			if (m == '$') ans++;

			que.push({ ni, nj });
			vis[ni][nj] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		init();

		while (!sp.empty())
		{
			array<int, 2> p = sp.front();
			sp.pop();

			bfs(p);
			key_check();
		}

		cout << ans << '\n';
	}

	return 0;
}
