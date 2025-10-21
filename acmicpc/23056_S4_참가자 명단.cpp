#include <iostream>
#include <queue>

using namespace std;
using pis = pair<int, string>;

int lim[11];

struct cmp
{
	bool operator() (const pis& a, const pis& b)
	{
		if (a.first != b.first) return a.first > b.first;
		int asz = a.second.size();
		int bsz = b.second.size();
		if (asz != bsz) return asz > bsz;
		else return a.second > b.second;
		return false;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, cls;
	string nam;
	priority_queue<pis, vector<pis>, cmp> od;
	priority_queue<pis, vector<pis>, cmp> ev;

	cin >> N >> M;
	while (true)
	{
		cin >> cls >> nam;
		if (!cls) break;
		if (lim[cls] >= M) continue;

		lim[cls]++;
		if (cls % 2) od.push({ cls, nam });
		else ev.push({ cls, nam });
	}

	while (!od.empty())
	{
		pis cur = od.top();
		od.pop();
		cout << cur.first << ' ' << cur.second << '\n';
	}

	while (!ev.empty())
	{
		pis cur = ev.top();
		ev.pop();
		cout << cur.first << ' ' << cur.second << '\n';
	}

	return 0;
}
