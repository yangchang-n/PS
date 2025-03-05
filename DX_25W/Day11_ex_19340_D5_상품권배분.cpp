#include <array>
#include <unordered_map>

using namespace std;

unordered_map<int, int> new_adr;
int total_head;
int total_depart;

struct Department
{
	int par;
	int pp;
	array<int, 3> sub;
} depart[30000];

int get_adr(int n)
{
	if (new_adr.find(n) != new_adr.end()) return new_adr[n];
	else
	{
		total_depart++;
		new_adr[n] = total_depart;
		return total_depart;
	}
}

void init(int N, int mId[], int mNum[])
{
	new_adr.clear();
	total_head = N;
	total_depart = 0;

	int tmp = 0;
	for (int i = 0; i < N; ++i)
	{
		tmp = get_adr(mId[i]);
		depart[tmp].par = 0;
		depart[tmp].pp = mNum[i];
		depart[tmp].sub.fill(0);
	}

	return;
}

int add(int mId, int mNum, int mParent)
{
	int p = get_adr(mParent);
	int anc;

	for (int i = 0; i < 3; ++i)
	{
		if (depart[p].sub[i] == 0)
		{
			int c = get_adr(mId);
			depart[p].sub[i] = c;

			anc = p;
			while (true)
			{
				depart[anc].pp += mNum;

				if (depart[anc].par == 0) break;
				else anc = depart[anc].par;
			}

			depart[c].par = p;
			depart[c].pp = mNum;
			depart[c].sub.fill(0);

			return depart[p].pp;
		}
		else if (i == 2) return -1;
	}
}

void del_depart(int r)
{
	depart[r].par = 0;
	depart[r].pp = 0;

	for (int i = 0; i < 3; ++i)
	{
		if (depart[r].sub[i] == 0) continue;

		del_depart(depart[r].sub[i]);
		depart[r].sub[i] = 0;
	}

	return;
}

int remove(int mId)
{
	if (new_adr.find(mId) == new_adr.end()) return -1;

	int r = get_adr(mId);
	int anc = depart[r].par;
	int ret = depart[r].pp;

	if (ret == 0) return -1;

	del_depart(r);

	for (int i = 0; i < 3; ++i)
	{
		if (depart[anc].sub[i] == r)
		{
			depart[anc].sub[i] = 0;
			break;
		}
	}

	while (true)
	{
		depart[anc].pp -= ret;

		if (depart[anc].par == 0) break;
		else anc = depart[anc].par;
	}

	return ret;
}

int distribute(int K)
{
	int total_pp = 0;
	int max_gift = 0;

	for (int i = 1; i <= total_head; ++i)
	{
		int tmp = depart[i].pp;
		total_pp += tmp;
		max_gift = max(max_gift, tmp);
	}

	if (K >= total_pp) return max_gift;

	int l = 1, r = max_gift;
	while (l <= r)
	{
		int k = K;
		int m = (l + r) / 2;

		for (int i = 1; i <= total_head; ++i)
		{
			int tmp = depart[i].pp;
			if (m > tmp) k -= tmp;
			else k -= m;
		}

		if (k >= 0)
		{
			l = m + 1;
			max_gift = m;
		}
		else r = m - 1;
	}

	return max_gift;
}
