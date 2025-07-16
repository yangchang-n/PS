#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

priority_queue<int> mx;
priority_queue<int, vector<int>, greater<int>> mn;
unordered_map<int, int> erase_mx;
unordered_map<int, int> erase_mn;

void ins(int n)
{
	mx.push(n);
	mn.push(n);

	if (!erase_mx.count(n)) erase_mx[n] = 0;
	if (!erase_mn.count(n)) erase_mn[n] = 0;
}

void sync_mx()
{
	while (!mx.empty() && erase_mx[mx.top()])
	{
		erase_mx[mx.top()]--;
		mx.pop();
	}
}

void sync_mn()
{
	while (!mn.empty() && erase_mn[mn.top()])
	{
		erase_mn[mn.top()]--;
		mn.pop();
	}
}

void del(int n)
{
	if (n == 1)
	{
		sync_mx();
		if (!mx.empty())
		{
			erase_mn[mx.top()]++;
			mx.pop();
		}
	}
	else
	{
		sync_mn();
		if (!mn.empty())
		{
			erase_mx[mn.top()]++;
			mn.pop();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		mx = priority_queue<int>();
		mn = priority_queue<int, vector<int>, greater<int>>();
		erase_mx.clear();
		erase_mn.clear();

		int k, n;
		char opt;
		cin >> k;

		for (int i = 0; i < k; ++i)
		{
			cin >> opt >> n;

			if (opt == 'I') ins(n);
			else del(n);
		}

		sync_mx();
		sync_mn();

		if (mx.empty()) cout << "EMPTY\n";
		else cout << mx.top() << ' ' << mn.top() << '\n';
	}

	return 0;
}
