//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <unordered_set>

using namespace std;

int T, N, M, cnt;
unordered_set<string> us;
char str[51];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		us.clear();
		cnt = 0;

		cin >> N >> M;

		for (int i = 0; i < N; ++i)
		{
			cin >> str;
			us.insert(str);
		}

		for (int i = 0; i < M; ++i)
		{
			cin >> str;
			if (us.find(str) != us.end()) cnt++;
		}

		cout << '#' << tc << ' ' << cnt << '\n';
	}

	return 0;
}
