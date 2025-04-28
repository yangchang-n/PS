#include <iostream>
#include <queue>
#include <array>

using namespace std;

int R, C;
int fire[1000][1000];
bool vis[1000][1000] = {};

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };
const int INF = 1'000'001;

void bfs_fire(queue<array<int, 3>>& que)
{
    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();

        for (int d = 0; d < 4; ++d)
        {
            int ni = cur[1] + di[d];
            int nj = cur[2] + dj[d];

            if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
            if (fire[ni][nj] != INF) continue;

            fire[ni][nj] = cur[0] + 1;
            que.push({ cur[0] + 1, ni, nj });
        }
    }
}

int bfs_jh(queue<array<int, 3>>& que)
{
    int time = -1;

    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();

        if (cur[1] == 0 || cur[1] == R - 1 || cur[2] == 0 || cur[2] == C - 1)
        {
            time = cur[0] + 1;
            break;
        }

        for (int d = 0; d < 4; ++d)
        {
            int ni = cur[1] + di[d];
            int nj = cur[2] + dj[d];

            if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
            if (vis[ni][nj] || fire[ni][nj] <= cur[0] + 1) continue;

            vis[ni][nj] = true;
            que.push({ cur[0] + 1, ni, nj });
        }
    }

    return time;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;

    queue<array<int, 3>> que_fire;
    queue<array<int, 3>> que_jh;

    for (int i = 0; i < R; ++i)
    {
        string row;
        cin >> row;

        for (int j = 0; j < C; ++j)
        {
            char tmp = row[j];

            if (tmp == '#') fire[i][j] = -1;
            else if (tmp == 'F')
            {
                fire[i][j] = 0;
                que_fire.push({ 0, i, j });
            }
            else fire[i][j] = INF;

            if (tmp == 'J')
            {
                vis[i][j] = true;
                que_jh.push({ 0, i, j });
            }
        }
    }

    bfs_fire(que_fire);
    int time = bfs_jh(que_jh);

    if (time == -1) cout << "IMPOSSIBLE";
    else cout << time;

    return 0;
}
