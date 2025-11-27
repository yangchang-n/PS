#include <iostream>
#include <queue>

using namespace std;

int bul[100'010];
queue<int> que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) cin >> bul[i];

	int qln = 0;
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		while (!que.empty() && que.front() <= i)
		{
			que.pop();
			qln--;
		}
		bul[i] = (bul[i] + qln) % 2;
		if (i <= N - K && bul[i])
		{
			bul[i] = 0;
			que.push(i + K);
			qln++; cnt++;
		}
	}

	for (int i = N - K + 1; i < N; ++i)
	{
		if (bul[i])
		{
			cout << "Insomnia";
			return 0;
		}
	}

	cout << cnt;

	return 0;
}
