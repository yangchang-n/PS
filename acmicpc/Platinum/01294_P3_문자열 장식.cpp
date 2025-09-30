#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
	bool operator() (const string& a, const string& b)
	{
		int asz = a.size();
		int bsz = b.size();
		int mnz = min(asz, bsz);

		for (int i = 0; i < mnz; ++i)
		{
			if (a[i] != b[i]) return a[i] > b[i];
		}

		return asz < bsz;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	priority_queue<string, vector<string>, cmp> pq;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		pq.push(str);
	}

	while (!pq.empty())
	{
		string cur = pq.top();
		pq.pop();

		cout << cur[0];
		if (cur.size() > 1) pq.push(cur.substr(1));
	}

	return 0;
}
