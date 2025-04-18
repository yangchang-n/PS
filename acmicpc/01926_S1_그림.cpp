#include <iostream>
#include <queue>
#include <array>

using namespace std;

int paper[500][500];
bool vis[500][500];

const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> paper[i][j];
            vis[i][j] = false;
        }
    }

    int ans = 0, cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (paper[i][j] && !vis[i][j])
            {
                int area = 0;
                queue<array<int, 2>> que;
                cnt++;

                que.push({ i, j });
                vis[i][j] = true;
                area++;

                while (!que.empty())
                {
                    auto cur = que.front();
                    que.pop();

                    for (int d = 0; d < 4; ++d)
                    {
                        int ny = cur[0] + dy[d];
                        int nx = cur[1] + dx[d];

                        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        if (!paper[ny][nx] || vis[ny][nx]) continue;

                        que.push({ ny, nx });
                        vis[ny][nx] = true;
                        area++;
                    }
                }

                ans = max(ans, area);
            }
        }
    }

    cout << cnt << '\n' << ans;

    return 0;
}
