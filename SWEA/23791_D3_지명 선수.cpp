//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int a[50], b[50];
char ret[50];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("1_sample_input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N;
		cin >> N;

		for (int i = 0; i < N; ++i) a[i] = b[i] = 0;
		for (int i = 0; i < N; ++i) ret[i] = 'X';
		for (int i = 0; i < N; ++i) cin >> a[i];
		for (int i = 0; i < N; ++i) cin >> b[i];

		int ca = 0, cb = 0;
		for (int i = 0; i < N; ++i)
		{
			if (i % 2 == 0)
			{
				while (true)
				{
					if (ret[a[ca] - 1] == 'X')
					{
						ret[a[ca] - 1] = 'A';
						ca++;
						break;
					}
					else ca++;
				}
			}
			else
			{
				while (true)
				{
					if (ret[b[cb] - 1] == 'X')
					{
						ret[b[cb] - 1] = 'B';
						cb++;
						break;
					}
					else cb++;
				}
			}
		}

		for (int i = 0; i < N; ++i) cout << ret[i];
		cout << '\n';
	}

	return 0;
}
