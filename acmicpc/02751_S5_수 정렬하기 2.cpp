#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, tmp;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		pq.push(tmp);
	}

	for (int i = 0; i < N; ++i)
	{
		cout << pq.top() << '\n';
		pq.pop();
	}

	return 0;
}
