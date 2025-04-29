#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };

int N;
char grd[100][100];
bool vis[100][100];

int bfs_cnt(bool visible)
{
    int cnt = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j) vis[i][j] = false;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!vis[i][j])
            {
                queue<tuple<char, int, int>> que;
                que.push({ grd[i][j], i, j });
                vis[i][j] = true;
                cnt++;

                while (!que.empty())
                {
                    auto cur = que.front();
                    que.pop();

                    char clr = get<0>(cur);
                    int ci = get<1>(cur);
                    int cj = get<2>(cur);

                    for (int d = 0; d < 4; ++d)
                    {
                        int ni = ci + di[d];
                        int nj = cj + dj[d];

                        if (ni < 0 || ni >= N) continue;
                        if (nj < 0 || nj >= N) continue;
                        if (vis[ni][nj]) continue;

                        if (visible)
                        {
                            if (clr != grd[ni][nj]) continue;
                        }
                        else
                        {
                            if (clr == 'R' || clr == 'G')
                            {
                                if (grd[ni][nj] == 'B') continue;
                            }
                            else
                            {
                                if (grd[ni][nj] == 'R') continue;
                                if (grd[ni][nj] == 'G') continue;
                            }
                        }

                        que.push({ grd[ni][nj], ni, nj });
                        vis[ni][nj] = true;
                    }
                }
            }
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    string line;
    for (int i = 0; i < N; ++i)
    {
        cin >> line;
        for (int j = 0; j < N; ++j) grd[i][j] = line[j];
    }

    int c_cnt = bfs_cnt(true);
    int n_cnt = bfs_cnt(false);

    cout << c_cnt << ' ' << n_cnt;

    return 0;
}
