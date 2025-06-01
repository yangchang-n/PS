#include <iostream>
#include <cmath>

using namespace std;

double x[10'000];
double y[10'000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];

	double area = 0.0;
	for (int i = 0; i < N; ++i)
	{
		int p = (i + 1) % N;
		area += (x[i] * y[p]) - (x[p] * y[i]);
	}
	
	area = fabs(area) / 2.0;
	cout << fixed;
	cout.precision(1);
	cout << area;

	return 0;
}
