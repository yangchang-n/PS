#include <iostream>
#include <queue>
#include <array>

using namespace std;

int maz[100][100];
int dst[100][100];
bool vis[100][100];

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    cin.ignore();

    char tmp[101];
    for (int i = 0; i < N; ++i)
    {
        cin.getline(tmp, 101);
        for (int j = 0; j < M; ++j)
        {
            maz[i][j] = tmp[j] - '0';
            dst[i][j] = 10'001;
            vis[i][j] = false;
        }
    }

    queue<array<int, 3>> que;
    que.push({ 1, 0, 0 });
    dst[0][0] = 1;
    vis[0][0] = true;

    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();

        if (dst[cur[1]][cur[2]] < cur[0]) continue;

        for (int d = 0; d < 4; ++d)
        {
            int ni = cur[1] + di[d];
            int nj = cur[2] + dj[d];

            if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
            if (!maz[ni][nj] || vis[ni][nj] || dst[ni][nj] < cur[0] + 1) continue;

            que.push({ cur[0] + 1, ni, nj });
            dst[ni][nj] = cur[0] + 1;
            vis[ni][nj] = true;
        }
    }

    cout << dst[N - 1][M - 1];

    return 0;
}
