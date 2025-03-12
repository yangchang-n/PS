//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <unordered_set>

using namespace std;

double a[50];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("2_sample_input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		double ipt, before;
		bool inf = false;
		unordered_set<double> us;

		int N;
		cin >> N;

		cin >> ipt;
		a[0] = ipt;
		us.insert(ipt);

		if (N == 1)
		{
			cout << 1 << '\n';
			continue;
		}

		for (int i = 1; i < N; ++i)
		{
			before = ipt;

			cin >> ipt;
			a[i] = ipt;
			us.insert(ipt);

			if (ipt == before) inf = true;
		}

		if (inf)
		{
			cout << -1 << '\n';
			continue;
		}

		int ans = 0, cnt;

		double cur;
		bool big, same;
		for (auto itr = us.begin(); itr != us.end(); ++itr)
		{
			cur = *itr - 0.5;

			if (a[0] > cur) big = true;
			else big = false;

			cnt = 0;
			for (int i = 1; i < N; ++i)
			{
				if (N - i + cnt < ans) break;

				if		( big && a[i] < cur) cnt++, big = false;
				else if (!big && a[i] > cur) cnt++, big = true;
			}

			ans = max(ans, cnt);
		}

		if (a[0] == a[N - 1])
		{
			cur = a[0];
			same = true;
			cnt = 1;

			for (int i = 1; i < N; ++i)
			{
				if (N - i + cnt < ans) break;

				if (same)
				{
					if		(a[i] < cur) same = false, big = false;
					else if (a[i] > cur) same = false, big = true;
				}
				else
				{
					if		( big && a[i] < cur) cnt++, big = false;
					else if (!big && a[i] > cur) cnt++, big = true;
					else if (a[i] == cur) cnt++, same = true;
				}
			}

			ans = max(ans, cnt);
		}

		cout << ans << '\n';
	}

	return 0;
}
