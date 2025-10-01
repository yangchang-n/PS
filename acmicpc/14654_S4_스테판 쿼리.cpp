#include <iostream>

using namespace std;

int N;
int r[310][2];
int mxace = 0;
int mxnyd = 0;
bool winning = true;

bool win(int a, int b)
{
	if (a == b)
	{
		if (winning) return false;
		else return true;
	}
	else if (a == 2 && b == 1) return true;
	else if (a == 3 && b == 2) return true;
	else if (a == 1 && b == 3) return true;
	else if (a == 1 && b == 2) return false;
	else if (a == 2 && b == 3) return false;
	else if (a == 3 && b == 1) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < N; ++i) cin >> r[i][j];
	}

	int cur = 0;
	for (int i = 0; i < N; ++i)
	{
		if (winning)
		{
			if (win(r[i][0], r[i][1])) cur++;
			else
			{
				mxace = max(mxace, cur);
				winning = false;
				cur = 1;
			}
		}
		else
		{
			if (win(r[i][0], r[i][1]))
			{
				mxnyd = max(mxnyd, cur);
				winning = true;
				cur = 1;
			}
			else cur++;
		}
	}

	if (winning) mxace = max(mxace, cur);
	else mxnyd = max(mxnyd, cur);

	cout << max(mxace, mxnyd);

	return 0;
}
