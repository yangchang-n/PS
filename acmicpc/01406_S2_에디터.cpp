#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string init_str;
	list<char> notepad;

	cin >> init_str;
	for (auto c : init_str) notepad.push_back(c);
	auto itr = notepad.end();

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		char opt;
		cin >> opt;

		if (opt == 'P')
		{
			char n;
			cin >> n;
			notepad.insert(itr, n);
		}
		else if (opt == 'B')
		{
			if (itr != notepad.begin())
			{
				itr--;
				itr = notepad.erase(itr);
			}
		}
		else if (opt == 'L')
		{
			if (itr != notepad.begin()) itr--;
		}
		else if (opt == 'D')
		{
			if (itr != notepad.end()) itr++;
		}
	}

	for (auto c : notepad) cout << c;

	return 0;
}
