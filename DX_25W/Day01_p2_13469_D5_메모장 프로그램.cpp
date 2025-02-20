#include <deque>

using namespace std;

int h, w, cur_y, cur_x, last_y, last_x;
deque<char> note[301];
int cnt_char[301][26];

void init(int H, int W, char mStr[])
{
	h = H, w = W;
	cur_y = cur_x = 0;
	last_y = last_x = 0;

	for (int i = 0; i <= 300; ++i)
	{
		note[i].clear();
		for (int j = 0; j < 26; ++j) cnt_char[i][j] = 0;
	}

	int cur = 0;
	while (true)
	{
		cur = last_y * w + last_x;
		if (mStr[cur] == '\0') break;

		note[last_y].push_back(mStr[cur]);
		cnt_char[last_y][mStr[cur] - 'a']++;
		last_x++;

		if (last_x == w)
		{
			last_y++;
			last_x = 0;
		}
	}

	return;
}

deque<char> temp;
void insert(char mChar)
{
	temp.clear();

	for (int i = 0; i < cur_x; ++i)
	{
		temp.push_back(note[cur_y].front());
		note[cur_y].pop_front();
	}
	temp.push_back(mChar);
	cnt_char[cur_y][mChar - 'a']++;
	while (!note[cur_y].empty())
	{
		temp.push_back(note[cur_y].front());
		note[cur_y].pop_front();
	}

	swap(temp, note[cur_y]);

	char new_line;
	for (int i = cur_y; i <= last_y; ++i)
	{
		if (note[i].size() > w)
		{
			new_line = note[i].back();
			note[i].pop_back();
			note[i + 1].push_front(new_line);

			cnt_char[i][new_line - 'a']--;
			cnt_char[i + 1][new_line - 'a']++;
		}
		else break;
	}

	cur_x++, last_x++;
	if (cur_x == w)
	{
		cur_y++;
		cur_x = 0;
	}
	if (last_x == w)
	{
		last_y++;
		last_x = 0;
	}

	return;
}

char moveCursor(int mRow, int mCol)
{
	if (mRow - 1 > last_y || (mRow - 1 == last_y && mCol - 1 >= last_x))
	{
		cur_y = last_y;
		cur_x = last_x;

		return '$';
	}

	cur_y = mRow - 1;
	cur_x = mCol - 1;

	return note[cur_y][cur_x];
}

int countCharacter(char mChar)
{
	int cnt = 0;

	for (int i = cur_x; i < note[cur_y].size(); ++i)
	{
		if (note[cur_y][i] == mChar) cnt++;
	}

	for (int i = cur_y + 1; i <= last_y; ++i)
	{
		cnt += cnt_char[i][mChar - 'a'];
	}

	return cnt;
}
