#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, ans = 0;
	cin >> N;

	ans += N / 5;
	ans += N / 25;
	ans += N / 125;

	cout << ans;

	return 0;
}
