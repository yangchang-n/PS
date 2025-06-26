#include <iostream>
#include <array>
#include <queue>

using namespace std;

bool vis[100'010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, ans = 0;
    cin >> N >> K;

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({ 0, N });
    vis[N] = true;

    while (!pq.empty())
    {
        int tim = pq.top()[0];
        int cur = pq.top()[1];
        pq.pop();

        if (cur == K)
        {
            ans = tim;
            break;
        }

        for (int c : {cur * 2, cur + 1, cur - 1})
        {
            if (c < 0 || c > 100'000) continue;
            if (vis[c]) continue;

            if (c == cur * 2) pq.push({ tim, c });
            else pq.push({ tim + 1, c });
            vis[c] = true;
        }
    }

    cout << ans;

    return 0;
}
