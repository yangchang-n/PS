#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<string> name(100'010);
	unordered_map<string, int> um;
	string pm;
	int num = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> pm;
		num++;

		name[num] = pm;
		um[pm] = num;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> pm;

		if (isdigit(pm[0]))
		{
			int tmp = stoi(pm);
			cout << name[tmp] << '\n';
		}
		else cout << um[pm] << '\n';
	}

	return 0;
}
