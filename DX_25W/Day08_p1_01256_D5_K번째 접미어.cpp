#define _CRT_SECURE_NO_WARNINGS
#define ALPHA_NUM 26

#include <iostream>
#include <string.h>

using namespace std;

int T, K, cur_k, ans_idx;
string str, ans;
char ans_temp[410];

int to_num(char c) { return c - 'a'; }
char to_alpha(int i) { return i + 'a'; }

struct TrieNode
{
	bool is_end = false;
	int children[ALPHA_NUM] = {0};
} trie_pool[300000];

void find_Kth(int cur_node)
{
	if (trie_pool[cur_node].is_end)
	{
		cur_k++;

		if (cur_k == K)
		{
			for (int i = 0; i < ans_idx; ++i) ans += ans_temp[i];
			return;
		}
	}

	for (int i = 0; i < ALPHA_NUM; ++i)
	{
		if (trie_pool[cur_node].children[i] == 0) continue;

		ans_temp[ans_idx] = to_alpha(i);
		ans_idx++;
		find_Kth(trie_pool[cur_node].children[i]);
		ans_idx--;
	}

	return;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		memset(trie_pool, 0, sizeof(trie_pool));

		cin >> K >> str;
		int sz = str.size();

		int root = 0, total = 1;

		for (int i = 0; i < sz; ++i)
		{
			int cur_node = root;
			int idx = i;

			while (true)
			{
				if (idx == sz)
				{
					trie_pool[cur_node].is_end = true;
					break;
				}

				int check = trie_pool[cur_node].children[to_num(str[idx])];

				if (check == 0)
				{
					trie_pool[cur_node].children[to_num(str[idx])] = total;

					cur_node = total;
					total++;
				}
				else cur_node = check;

				idx++;
			}
		}

		ans = "";
		cur_k = 0, ans_idx = 0;
		find_Kth(0);

		cout << '#' << tc << ' ' << ans << '\n';
	}
	
	return 0;
}
