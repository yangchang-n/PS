#include <iostream>

using namespace std;

int bd[26][2];
int hor[5];
int ver[5];
int dia[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tmp, bin = 0;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> tmp;
			bd[tmp][0] = i;
			bd[tmp][1] = j;
		}
	}

	for (int p = 1; p <= 25; ++p)
	{
		cin >> tmp;

		int i = bd[tmp][0];
		int j = bd[tmp][1];

		hor[i]++;
		if (hor[i] == 5) bin++;

		ver[j]++;
		if (ver[j] == 5) bin++;

		if (i == j)
		{
			dia[0]++;
			if (dia[0] == 5) bin++;
		}

		if (i + j == 4)
		{
			dia[1]++;
			if (dia[1] == 5) bin++;
		}

		if (bin >= 3)
		{
			cout << p;
			break;
		}
	}

	return 0;
}
