//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

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
		int N;
		cin >> N;

		double ipt, bfr;
		priority_queue<double> pq;
		bool inf = false;

		cin >> ipt;
		a[0] = ipt;
		pq.push(ipt);

		if (N == 1)
		{
			cout << 1 << '\n';
			continue;
		}

		for (int i = 1; i < N; ++i)
		{
			bfr = ipt;

			cin >> ipt;
			a[i] = ipt;
			pq.push(ipt);

			if (ipt == bfr) inf = true;
		}

		if (inf)
		{
			cout << -1 << '\n';
			continue;
		}

		double tmp, cur = 0.0;
		int ans = 0, cnt;
		bool big;
		while (!pq.empty())
		{
			tmp = cur;
			cur = pq.top() - 0.5;
			pq.pop();

			if (tmp == cur) continue;

			if (a[0] > cur) big = true;
			else big = false;

			cnt = 0;
			for (int i = 1; i < N; ++i)
			{
				if (N - i + cnt < ans) break;

				if (big && a[i] < cur)
				{
					cnt++;
					big = false;
				}
				else if (!big && a[i] > cur)
				{
					cnt++;
					big = true;
				}
			}

			ans = max(ans, cnt);
		}

		if (a[0] == a[N - 1])
		{
			cur = a[0];
			bool same = true;

			int cnt = 1;
			for (int i = 1; i < N; ++i)
			{
				if (N - i + cnt < ans) break;

				if (same && a[i] < cur)
				{
					big = false;
					same = false;
				}
				else if (same && a[i] > cur)
				{
					big = true;
					same = false;
				}
				else if (!same && big && a[i] < cur)
				{
					cnt++;
					big = false;
				}
				else if (!same && !big && a[i] > cur)
				{
					cnt++;
					big = true;
				}
				else if (!same && a[i] == cur)
				{
					cnt++;
					same = true;
				}
			}

			ans = max(ans, cnt);
		}

		cout << ans << '\n';
	}

	return 0;
}
