#include <iostream>
#include <queue>

using namespace std;

class GravQue
{
private :
	deque<char> d;
	int state = 0;
	int cnt_b = 0;
	int cnt_w = 0;

public :
	void fall()
	{
		if (this->d.empty()) return;
		if (this->state == 1)
		{
			while (!this->d.empty())
			{
				char cur = this->d.front();
				if (cur == 'w') break;
				this->d.pop_front();
				this->cnt_b--;
			}
		}
		else if (this->state == 3)
		{
			while (!this->d.empty())
			{
				char cur = this->d.back();
				if (cur == 'w') break;
				this->d.pop_back();
				this->cnt_b--;
			}
		}
	}

	void push(char c)
	{
		if (c == 'b')
		{
			if (this->state == 1 && this->cnt_w == 0) return;
			if (this->state == 3) return;
		}
		this->d.push_back(c);
		if (c == 'b') this->cnt_b++;
		if (c == 'w') this->cnt_w++;
	}

	void pop()
	{
		if (this->d.empty()) return;
		char c = this->d.front();
		this->d.pop_front();
		if (c == 'b') this->cnt_b--;
		if (c == 'w') this->cnt_w--;
		if (this->state % 2) this->fall();
	}

	void rotate(char c)
	{
		this->state += 4;
		if (c == 'r') this->state++;
		if (c == 'l') this->state--;
		this->state %= 4;
		if (this->state % 2) this->fall();
	}

	void count(char c)
	{
		if (c == 'b') cout << this->cnt_b << '\n';
		if (c == 'w') cout << this->cnt_w << '\n';
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	GravQue gq = GravQue();
	int q;
	cin >> q;
	while (q--)
	{
		string opt; char m;
		cin >> opt;
		if (opt == "pop")
		{
			gq.pop();
			continue;
		}
		cin >> m;
		if      (opt == "push")   gq.push(m);
		else if (opt == "rotate") gq.rotate(m);
		else if (opt == "count")  gq.count(m);
	}

	return 0;
}
