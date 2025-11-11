#include <iostream>
#include <array>

using namespace std;

struct Node
{
	array<int, 2> p;
	array<int, 2> l;
} node[15];
bool done = false;
bool used[15];
int star[5][9];
int line[8];

void init()
{
	node[1]  = { {0, 4}, {1, 3} };
	node[2]  = { {1, 1}, {4, 6} };
	node[3]  = { {1, 3}, {1, 6} };
	node[4]  = { {1, 5}, {3, 6} };
	node[5]  = { {1, 7}, {5, 6} };
	node[6]  = { {2, 2}, {1, 4} };
	node[7]  = { {2, 6}, {3, 5} };
	node[8]  = { {3, 1}, {1, 2} };
	node[9]  = { {3, 3}, {2, 4} };
	node[10] = { {3, 5}, {2, 5} };
	node[11] = { {3, 7}, {2, 3} };
	node[12] = { {4, 4}, {4, 5} };

	for (int i = 0; i < 5; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 9; ++j)
		{
			if (str[j] == '.') continue;
			if (str[j] == 'x') continue;
			int a = str[j] - 'A' + 1;
			used[a] = true;
			star[i][j] = a;
			for (int n = 1; n <= 12; ++n)
			{
				if (node[n].p[0] != i) continue;
				if (node[n].p[1] != j) continue;
				line[node[n].l[0]] += a;
				line[node[n].l[1]] += a;
			}
		}
	}
}

void bkt(int n)
{
	if (n == 13)
	{
		done = true;
		return;
	}
	int ci = node[n].p[0];
	int cj = node[n].p[1];
	if (star[ci][cj])
	{
		bkt(n + 1);
		return;
	}

	int l0 = node[n].l[0];
	int l1 = node[n].l[1];
	for (int a = 1; a <= 12; ++a)
	{
		if (used[a]) continue;
		if (line[l0] + a > 26) continue;
		if (line[l1] + a > 26) continue;

		used[a] = true;
		star[ci][cj] = a;
		line[l0] += a;
		line[l1] += a;

		bkt(n + 1);
		if (done) return;

		used[a] = false;
		star[ci][cj] = 0;
		line[l0] -= a;
		line[l1] -= a;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	bkt(1);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (!star[i][j]) cout << '.';
			else
			{
				char c = star[i][j] - 1 + 'A';
				cout << c;
			}
		}
		cout << '\n';
	}

	return 0;
}
