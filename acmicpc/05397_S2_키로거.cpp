#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		string input;
		cin >> input;

		list<char> password;
		auto cursor = password.begin();

		for (auto i : input)
		{
			if (i == '-')
			{
				if (cursor != password.begin())
				{
					cursor--;
					cursor = password.erase(cursor);
				}
			}
			else if (i == '<')
			{
				if (cursor != password.begin()) cursor--;
			}
			else if (i == '>')
			{
				if (cursor != password.end()) cursor++;
			}
			else
			{
				password.insert(cursor, i);
			}
		}

		for (auto c : password) cout << c;
		cout << '\n';
	}

	return 0;
}
