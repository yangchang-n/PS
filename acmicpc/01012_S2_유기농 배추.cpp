#include <iostream>
#include <array>
#include <queue>

using namespace std;

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };

int M, N;
int fld[50][50];
int vis[50][50];

int solve()
{
    int ans = 0;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (fld[i][j] && !vis[i][j])
            {
                ans++;

                queue<array<int, 2>> que;
                que.push({ i, j });
                vis[i][j] = 1;

                while (!que.empty())
                {
                    auto cur = que.front();
                    que.pop();

                    for (int d = 0; d < 4; ++d)
                    {
                        int ni = cur[0] + di[d];
                        int nj = cur[1] + dj[d];

                        if (ni < 0 || ni >= M) continue;
                        if (nj < 0 || nj >= N) continue;
                        if (!fld[ni][nj]) continue;
                        if (vis[ni][nj]) continue;

                        que.push({ ni, nj });
                        vis[ni][nj] = 1;
                    }
                }
            }
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc)
    {
        int K;
        cin >> M >> N >> K;

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                fld[i][j] = 0;
                vis[i][j] = 0;
            }
        }

        int m, n;
        for (int i = 0; i < K; ++i)
        {
            cin >> m >> n;
            fld[m][n] = 1;
        }

        cout << solve() << '\n';
    }

    return 0;
}
