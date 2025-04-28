#include <iostream>
#include <queue>

using namespace std;

int vis[100'001] = {};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, ans;
    cin >> N >> K;

    queue<int> que;
    que.push(N);
    vis[N] = 1;

    while (!que.empty())
    {
        int cur = que.front();
        int tim = vis[cur];
        que.pop();

        if (cur == K)
        {
            ans = tim - 1;
            break;
        }

        for (int t : {cur * 2, cur + 1, cur - 1})
        {
            if (t < 0 || t > 100'000) continue;
            if (vis[t]) continue;

            que.push(t);
            vis[t] = tim + 1;
        }
    }

    cout << ans;

    return 0;
}
