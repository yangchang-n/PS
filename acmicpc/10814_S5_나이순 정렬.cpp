#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;
map<int, vector<string>> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int age;
		string name;
		cin >> age >> name;

		if (!mp.count(age)) mp[age] = { name };
		else mp[age].push_back(name);
	}

	for (auto a : mp)
	{
		for (int i = 0; i < a.second.size(); ++i)
		{
			cout << a.first << ' ' << a.second[i] << '\n';
		}
	}

	return 0;
}
