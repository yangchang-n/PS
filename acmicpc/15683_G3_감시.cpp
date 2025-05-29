#include <iostream>

using namespace std;

const int di[4] = { 0, 1, 0, -1 };
const int dj[4] = { 1, 0, -1, 0 };

int N, M;
int map[8][8];
int cam[8][3];
int cam_cnt = 0;
int ans = 64, cnt = 0;
// int cnt_cnt = 0;

int mark(int p, int ni, int nj, bool erase)
{
	if (ni < 0 || ni >= N) return 0;
	if (nj < 0 || nj >= M) return 0;
	if (map[ni][nj] == 6) return 0;
	if (map[ni][nj] == 0 && !erase) map[ni][nj] = p + 7;
	if (map[ni][nj] == p + 7 && erase) map[ni][nj] = 0;
	return 1;
}

void bkt(int p)
{
	if (p == cam_cnt)
	{
		cnt = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (!map[i][j]) cnt++;
			}
		}

		// cnt_cnt++;
		// cout << cnt << '\n';

		ans = min(ans, cnt);
		return;
	}

	int ci = cam[p][1];
	int cj = cam[p][2];
	int ni, nj;

	if (cam[p][0] == 1)
	{
		for (int d = 0; d < 4; ++d)
		{
			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d];
				nj = nj + dj[d];
				if (!mark(p, ni, nj, false)) break;
			}

			bkt(p + 1);

			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d];
				nj = nj + dj[d];
				if (!mark(p, ni, nj, true)) break;
			}
		}
	}
	else if (cam[p][0] == 2)
	{
		for (int d = 0; d < 2; ++d)
		{
			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d];
				nj = nj + dj[d];
				if (!mark(p, ni, nj, false)) break;
			}
			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d + 2];
				nj = nj + dj[d + 2];
				if (!mark(p, ni, nj, false)) break;
			}

			bkt(p + 1);

			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d];
				nj = nj + dj[d];
				if (!mark(p, ni, nj, true)) break;
			}
			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d + 2];
				nj = nj + dj[d + 2];
				if (!mark(p, ni, nj, true)) break;
			}
		}
	}
	else if (cam[p][0] == 3)
	{
		ni = ci, nj = cj;
		while (true)
		{
			ni = ni + di[3];
			nj = nj + dj[3];
			if (!mark(p, ni, nj, false)) break;
		}

		for (int d = 0; d < 4; ++d)
		{
			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d];
				nj = nj + dj[d];
				if (!mark(p, ni, nj, false)) break;
			}

			bkt(p + 1);

			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d - 1 < 0 ? 3 : d - 1];
				nj = nj + dj[d - 1 < 0 ? 3 : d - 1];
				if (!mark(p, ni, nj, true)) break;
			}
		}

		ni = ci, nj = cj;
		while (true)
		{
			ni = ni + di[3];
			nj = nj + dj[3];
			if (!mark(p, ni, nj, true)) break;
		}
	}
	else if (cam[p][0] == 4)
	{
		for (int d = 0; d < 4; ++d)
		{
			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d];
				nj = nj + dj[d];
				if (!mark(p, ni, nj, false)) break;
			}
		}

		for (int d = 0; d < 4; ++d)
		{
			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d];
				nj = nj + dj[d];
				if (!mark(p, ni, nj, true)) break;
			}

			bkt(p + 1);

			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d];
				nj = nj + dj[d];
				if (!mark(p, ni, nj, false)) break;
			}
		}

		for (int d = 0; d < 4; ++d)
		{
			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d];
				nj = nj + dj[d];
				if (!mark(p, ni, nj, true)) break;
			}
		}
	}
	else if (cam[p][0] == 5)
	{
		for (int d = 0; d < 4; ++d)
		{
			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d];
				nj = nj + dj[d];
				if (!mark(p, ni, nj, false)) break;
			}
		}

		bkt(p + 1);

		for (int d = 0; d < 4; ++d)
		{
			ni = ci, nj = cj;
			while (true)
			{
				ni = ni + di[d];
				nj = nj + dj[d];
				if (!mark(p, ni, nj, true)) break;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> tmp;
			map[i][j] = tmp;
			if (tmp > 0 && tmp < 6)
			{
				cam[cam_cnt][0] = tmp;
				cam[cam_cnt][1] = i;
				cam[cam_cnt][2] = j;
				cam_cnt++;
			}
		}
	}

	bkt(0);

	// cout << cnt_cnt << '\n';
	cout << ans;

	return 0;
}
