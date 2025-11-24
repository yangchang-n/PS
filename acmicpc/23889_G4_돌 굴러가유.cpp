#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;
using ai2 = array<int, 2>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;

	vector<int> cas(N + 1, 0);
	vector<int> roc(K + 1, 0);
	vector<bool> bd(K + 1, true);
	priority_queue<ai2, vector<ai2>, greater<ai2>> pq;

	for (int i = 1; i <= N; ++i) cin >> cas[i];
	for (int i = 1; i <= K; ++i) cin >> roc[i];
	for (int i = 1; i < K; ++i)
	{
		int sm = 0;
		for (int j = roc[i]; j < roc[i + 1]; ++j) sm += cas[j];
		pq.push({ sm, -i });
	}
	int sm = 0;
	for (int j = roc[K]; j <= N; ++j) sm += cas[j];
	pq.push({ sm, -K });

	int cnt = K - M;
	while (!pq.empty() && cnt--)
	{
		auto cur = pq.top();
		pq.pop();
		bd[-cur[1]] = false;
	}

	for (int i = 1; i <= K; ++i)
	{
		if (bd[i]) cout << roc[i] << '\n';
	}

	return 0;
}
