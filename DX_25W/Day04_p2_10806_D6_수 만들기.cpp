#include <iostream>
#include <array>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
        int N, K, ans;
        int num[10] = {};
        
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> num[i];
        cin >> K;

        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;

        pq.push({0, K});
        while (pq.top()[1])
        {
            int cur[2] = {pq.top()[0], pq.top()[1]};
            pq.pop();

            pq.push({cur[0] + cur[1], 0});
            for (int i = 0; i < N; ++i)
            {
                pq.push({cur[0] + (cur[1] % num[i]), cur[1] / num[i]});
            }
            
            ans = pq.top()[0];
        }

        cout << '#' << test_case << ' ' << ans << '\n';
	}
    
	return 0;
}
