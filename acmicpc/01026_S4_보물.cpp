#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[60];
int b[60];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> a[i];
	for (int i = 0; i < N; ++i) cin >> b[i];

	sort(a, a + N);
	sort(b, b + N, greater<int>());

	int ans = 0;
	for (int i = 0; i < N; ++i) ans += a[i] * b[i];

	cout << ans;

	return 0;
}
