#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	list<int> ppl;
	for (int i = 1; i <= N; ++i) ppl.push_back(i);
	auto itr = ppl.begin();

	cout << '<';

	for (int i = 1; i < K; ++i) itr++;
	cout << *itr;
	itr = ppl.erase(itr);

	while (!ppl.empty())
	{
		for (int i = 1; i < K; ++i)
		{
			if (itr == ppl.end()) itr = ppl.begin();
			itr++;
			if (itr == ppl.end()) itr = ppl.begin();
		}

		cout << ", " << *itr;

		if (itr == ppl.end())
		{
			ppl.erase(itr);
			itr = ppl.begin();
		}
		else itr = ppl.erase(itr);
	}

	cout << '>';

	return 0;
}
