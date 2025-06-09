#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	double dx21 = x2 - x1;
	double dy21 = y2 - y1;
	double dx32 = x3 - x2;
	double dy32 = y3 - y2;

	double tmp;
	if (dx21 > 0)
	{
		if (dx32 > 0)
		{
			tmp = (dy32 / dx32) - (dy21 / dx21);
			if (tmp > 0) cout << 1;
			else if (tmp < 0) cout << -1;
			else cout << 0;
		}
		else if (dx32 < 0)
		{
			tmp = (dy32 / dx32) - (dy21 / dx21);
			if (tmp > 0) cout << -1;
			else if (tmp < 0) cout << 1;
			else cout << 0;
		}
		else
		{
			if (dy32 > 0) cout << 1;
			else cout << -1;
		}
	}
	else if (dx21 < 0)
	{
		if (dx32 > 0)
		{
			tmp = (dy32 / dx32) - (dy21 / dx21);
			if (tmp > 0) cout << -1;
			else if (tmp < 0) cout << 1;
			else cout << 0;
		}
		else if (dx32 < 0)
		{
			tmp = (dy32 / dx32) - (dy21 / dx21);
			if (tmp > 0) cout << 1;
			else if (tmp < 0) cout << -1;
			else cout << 0;
		}
		else
		{
			if (dy32 > 0) cout << -1;
			else cout << 1;
		}
	}
	else
	{
		if (dy21 > 0)
		{
			if (dx32 > 0) cout << -1;
			else if (dx32 < 0) cout << 1;
			else cout << 0;
		}
		else if (dy21 < 0)
		{
			if (dx32 > 0) cout << 1;
			else if (dx32 < 0) cout << -1;
			else cout << 0;
		}
	}

	return 0;
}
