#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	string name;
	unordered_set<string> us;
	vector<string> ans;
	int cnt = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> name;
		us.insert(name);
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> name;
		if (us.count(name))
		{
			ans.push_back(name);
			cnt++;
		}
	}

	sort(ans.begin(), ans.end());

	cout << cnt << '\n';
	for (int i = 0; i < cnt; ++i)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}
