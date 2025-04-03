#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

#include <iostream>

int main()
{
	fastIO;

	int N;
	cin >> N;

	N <<= 1;

	int tmp = N - 1, p = 0;
	while (tmp != 1)
	{
		tmp >>= 1;
		p++;
	}

	int M = 1 << p;

	cout << N - M;

	return 0;
}

/*
n = 1 = 1
a = 1 = 1

n = 2 = 10
a = 2 = 10

n = 3 = 11
a = 2 = 10

n = 4 = 100
a = 4 = 100

n = 5 = 101
a = 2 = 010

n = 6 = 110
a = 4 = 100

n = 7 = 111
a = 6 = 110

n = 8 = 1000
a = 8 = 1000

n = 17 = 10001
a = 2 = 00010

n = 23 = 10111
a = 14 = 01110

n = 31 = 11111
a = 30 = 11110
*/
