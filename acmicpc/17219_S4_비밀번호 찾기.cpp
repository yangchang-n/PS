#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	unordered_map<string, string> um;

	for (int i = 0; i < N; ++i)
	{
		string adr, pas;
		cin >> adr >> pas;

		um[adr] = pas;
	}

	for (int i = 0; i < M; ++i)
	{
		string adr;
		cin >> adr;

		cout << um[adr] << '\n';
	}

	return 0;
}
