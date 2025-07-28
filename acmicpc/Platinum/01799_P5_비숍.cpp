#include <iostream>
#include <array>
#include <vector>

using namespace std;

int N;
int bd[10][10];
bool vis_up[20] = {};
bool vis_dw[20] = {};

vector<array<int, 2>> ev;
vector<array<int, 2>> od;

int cnt = 0;
int ans = 0;

void bkt(vector<array<int, 2>>& vt, int n, int c)
{
	if (n == vt.size())
	{
		cnt = max(c, cnt);
		return;
	}

	for (int p = n; p < vt.size(); ++p)
	{
		int i = vt[p][0];
		int j = vt[p][1];

		if (vis_up[i + j]) continue;
		if (vis_dw[i - j + N]) continue;

		vis_up[i + j] = true;
		vis_dw[i - j + N] = true;

		bkt(vt, p + 1, c + 1);

		vis_up[i + j] = false;
		vis_dw[i - j + N] = false;
	}

	cnt = max(c, cnt);
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int tmp;
			cin >> tmp;

			bd[i][j] = tmp;

			if (tmp)
			{
				if ((i + j) % 2) ev.push_back({ i, j });
				else od.push_back({ i, j });
			}
		}
	}

	cnt = 0;
	bkt(ev, 0, 0);
	ans += cnt;

	cnt = 0;
	bkt(od, 0, 0);
	ans += cnt;

	cout << ans;

	return 0;
}
