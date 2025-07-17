#include <iostream>

using namespace std;

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };

int R, C, ans = 0;
int bd[20][20];
bool vs[26];

void bkt(int i, int j, int cnt)
{
    ans = max(ans, cnt);
    
	for (int d = 0; d < 4; ++d)
	{
		int ni = i + di[d];
		int nj = j + dj[d];

		if (ni < 0 || ni >= R) continue;
		if (nj < 0 || nj >= C) continue;
		if (vs[bd[ni][nj]]) continue;
        
		vs[bd[ni][nj]] = true;
		bkt(ni, nj, cnt + 1);
		vs[bd[ni][nj]] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		string line;
		cin >> line;
		for (int j = 0; j < C; ++j) bd[i][j] = line[j] - 'A';
	}

	for (int i = 0; i < 26; ++i) vs[i] = false;

	vs[bd[0][0]] = true;
	bkt(0, 0, 1);

	cout << ans;

	return 0;
}
