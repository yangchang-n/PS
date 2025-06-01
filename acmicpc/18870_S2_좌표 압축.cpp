#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int num[1'000'010];
priority_queue<int, vector<int>, greater<int>> que;
unordered_map<int, int> um;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		num[i] = tmp;
		que.push(tmp);
	}

	int press = 0;
	int pre = 1'000'000'010;
	while (!que.empty())
	{
		tmp = que.top();
		que.pop();
		if (tmp != pre) um[tmp] = press++;
		pre = tmp;
	}

	for (int i = 0; i < N; ++i)
	{
		cout << um[num[i]] << ' ';
	}

	return 0;
}
