#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int A, B, tmp;
		bool valid = true;
		unordered_set<int> us;
		cin >> A >> B;

		if (A == B)
		{
			for (int i = 0; i < A; ++i)
			{
				cin >> tmp;
				us.insert(tmp);
			}
			for (int i = 0; i < B; ++i)
			{
				cin >> tmp;
				if (valid && !us.count(tmp)) valid = false;
			}

			cout << (valid ? "=\n" : "?\n");
		}
		else if (A > B)
		{
			for (int i = 0; i < A; ++i)
			{
				cin >> tmp;
				us.insert(tmp);
			}
			for (int i = 0; i < B; ++i)
			{
				cin >> tmp;
				if (valid && !us.count(tmp)) valid = false;
			}

			cout << (valid ? ">\n" : "?\n");
		}
		else
		{
			int can[50];
			for (int i = 0; i < A; ++i)
			{
				cin >> tmp;
				can[i] = tmp;
			}
			for (int i = 0; i < B; ++i)
			{
				cin >> tmp;
				us.insert(tmp);
			}
			for (int i = 0; i < A; ++i)
			{
				if (valid && !us.count(can[i])) valid = false;
			}

			cout << (valid ? "<\n" : "?\n");
		}
	}

	return 0;
}
