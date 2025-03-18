#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int tc = 1; tc <= 10; ++tc)
	{
		int N, ans = 0;
		deque<int> b_info;

		cin >> N;

		if (N == 4)
		{
			cout << '#' << tc << ' ' << 0 << '\n';
			continue;
		}

		int tmp;
		for (int i = 0; i < N; ++i)
		{
			cin >> tmp;
			b_info.push_back(tmp);

			if (i < 4) continue;
			if (i != 4) b_info.pop_front();

			int target = b_info[2];

			int comp = b_info[0];
			for (int j = 1; j < 5; ++j)
			{
				if (j == 2) continue;
				comp = max(comp, b_info[j]);
			}

			target -= comp;

			if (target > 0) ans += target;
		}

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}
