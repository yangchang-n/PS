#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, t;
int cnt = 200;
vector<vector<int>> p(200);

void bkt(int c, const vector<int>& v)
{
	if (c > 155) return;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == 0)
		{
			cnt = min(cnt, c);
			break;
		}
		bkt(c + 1, p[v[i]]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		p[t].push_back(i);
	}

	bkt(1, p[k]);

	cout << (cnt == 200 ? -1 : cnt);

	return 0;
}
