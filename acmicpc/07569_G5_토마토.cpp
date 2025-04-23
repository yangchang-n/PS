#include <iostream>
#include <queue>
#include <array>

using namespace std;

int tom[100][100][100];

const int di[6] = { 1, -1, 0, 0, 0, 0 };
const int dj[6] = { 0, 0, 1, -1, 0, 0 };
const int dk[6] = { 0, 0, 0, 0, 1, -1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, H;
    cin >> M >> N >> H;

    int tmp, cnt = 0;
    bool vld = false;
    queue<array<int, 4>> que;

    for (int k = 0; k < H; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cin >> tmp;
                tom[i][j][k] = tmp;
                if (tmp == 1) que.push({ 1, i, j, k });
                if (!tmp)
                {
                    cnt++;
                    if (!vld) vld = true;
                }
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

        ans = cur[0];

        for (int d = 0; d < 6; ++d)
        {
            int ni = cur[1] + di[d];
            int nj = cur[2] + dj[d];
            int nk = cur[3] + dk[d];

            if (ni < 0 || ni >= N) continue;
            if (nj < 0 || nj >= M) continue;
            if (nk < 0 || nk >= H) continue;
            if (tom[ni][nj][nk]) continue;

            que.push({ cur[0] + 1, ni, nj, nk });
            tom[ni][nj][nk] = 1;
            cnt--;
        }
    }

    if (cnt) cout << -1;
    else cout << --ans;

    return 0;
}
