#include <iostream>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	ll cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

	if (cross > 0) cout << 1;
	else if (cross < 0) cout << -1;
	else cout << 0;

	return 0;
}
