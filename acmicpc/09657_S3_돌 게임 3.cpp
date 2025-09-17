#include <iostream>

using namespace std;

bool SK[1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	SK[1] = true;
	SK[2] = false;
	SK[3] = true;
	SK[4] = true;
	SK[5] = true;
	SK[6] = true;

	int N;
	cin >> N;
	for (int i = 7; i <= N; ++i)
	{
		if (!SK[i - 1] || !SK[i - 3] || !SK[i - 4]) SK[i] = true;
	}

	if (SK[N]) cout << "SK";
	else cout << "CY";

	return 0;
}
