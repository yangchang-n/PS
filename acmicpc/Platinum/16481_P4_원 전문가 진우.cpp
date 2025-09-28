#include <iostream>
#include <iomanip>

using namespace std;
using ld = long double;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ld r1, r2, r3;
	cin >> r1 >> r2 >> r3;

	ld ans = (r1 * r2 * r3) / (r1 * r2 + r2 * r3 + r3 * r1);
	cout << fixed << setprecision(8);
	cout << ans;

	return 0;
}
