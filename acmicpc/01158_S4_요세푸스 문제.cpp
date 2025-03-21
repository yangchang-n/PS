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

	while (N)
	{
		for (int i = 1; i < K; ++i)
		{
			itr++;
			if (itr == ppl.end()) itr = ppl.begin();
		}

		N--;
		if (!N) cout << *itr << '>';
		else cout << *itr << ", ";

		itr = ppl.erase(itr);
		if (itr == ppl.end()) itr = ppl.begin();
	}

	return 0;
}
