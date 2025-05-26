#include <iostream>

using namespace std;

int N, M;
int arr[10] = {};
bool is_used[10] = {};

void backtracking(int p)
{
	if (p == M)
	{
		for (int i = 0; i < M; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!is_used[i])
		{
			arr[p] = i;
			is_used[i] = true;
			backtracking(p + 1);
			is_used[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	backtracking(0);

	return 0;
}
