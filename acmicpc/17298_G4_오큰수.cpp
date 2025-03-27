#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
// using ll = long long;

#include <iostream>

int NGE[1'000'000];
int num[1'000'000][2];
int pos = 0;

int main()
{
	fastIO;

	int N, A;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> A;

		while (pos)
		{
			if (num[pos - 1][0] < A) NGE[num[--pos][1]] = A;
			else break;
		}

		num[pos][0] = A;
		num[pos][1] = i;
		pos++;
	}

	while (pos) NGE[num[--pos][1]] = -1;

	for (int i = 0; i < N; ++i) cout << NGE[i] << ' ';

	return 0;
}
