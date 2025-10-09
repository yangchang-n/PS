#include <iostream>

using namespace std;

bool exist[4][14];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string card;
	cin >> card;

	for (int i = 0; i < card.size(); i += 3)
	{
		int p = 0;
		if (card[i] == 'P') p = 0;
		else if (card[i] == 'K') p = 1;
		else if (card[i] == 'H') p = 2;
		else if (card[i] == 'T') p = 3;

		int n = (int)(card[i + 1] - '0') * 10 + (int)(card[i + 2] - '0');

		if (exist[p][n])
		{
			cout << "GRESKA";
			return 0;
		}
		else exist[p][n] = true;
	}

	for (int p = 0; p < 4; ++p)
	{
		int cnt = 0;
		for (int n = 1; n < 14; ++n)
		{
			if (!exist[p][n]) cnt++;
		}
		cout << cnt << ' ';
	}

	return 0;
}
