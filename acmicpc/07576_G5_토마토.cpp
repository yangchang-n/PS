#include <iostream>
#include <queue>
#include <array>

using namespace std;

int tom[1000][1000];

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    int tmp, cnt = 0;
    bool vld = false;
    queue<array<int, 3>> que;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> tmp;
            tom[i][j] = tmp;
            if (tmp == 1) que.push({ 1, i, j });
            if (!tmp)
            {
                cnt++;
                if (!vld) vld = true;
            }
        }
    }

    if (!vld)
    {
        cout << 0;
        return 0;
    }

    int ans = 0;
    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();

        ans = max(ans, cur[0]);

        for (int d = 0; d < 4; ++d)
        {
            int ni = cur[1] + di[d];
            int nj = cur[2] + dj[d];

            if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
            if (tom[ni][nj] == -1) continue;
            if (tom[ni][nj] > 0) continue;

            que.push({ cur[0] + 1, ni, nj });
            tom[ni][nj] = cur[0] + 1;
            cnt--;
        }
    }

    if (cnt) cout << -1;
    else cout << --ans;

    return 0;
}
