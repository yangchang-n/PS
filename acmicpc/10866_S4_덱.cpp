#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

#include <iostream>

class Deque
{
private:
	int* dta;
	int f, b;
	int MX = 10000;

public:
	Deque()
	{
		dta = new int[MX * 2 + 1];
		f = b = MX;
	}
	~Deque() { delete[] dta; }

	void push_front(int n) { dta[--f] = n; }
	void push_back (int n) { dta[b++] = n; }
	int pop_front()
	{
		if (b - f == 0) return -1;
		else return dta[f++];
	}
	int pop_back()
	{
		if (b - f == 0) return -1;
		else return dta[--b];
	}
	int size() { return b - f; }
	int empty()
	{
		if (b - f == 0) return 1;
		else return 0;
	}
	int front()
	{
		if (b - f == 0) return -1;
		else return dta[f];
	}
	int back()
	{
		if (b - f == 0) return -1;
		else return dta[b - 1];
	}
};

int main()
{
	fastIO;

	int N, num;
	cin >> N;

	Deque dq;

	char opt[11];
	for (int i = 0; i < N; ++i)
	{
		cin >> opt;

		if (opt[0] == 'p')
		{
			if (opt[5] == 'f')
			{
				cin >> num;
				dq.push_front(num);
			}
			else if (opt[5] == 'b')
			{
				cin >> num;
				dq.push_back(num);
			}
			else if (opt[5] == 'r') cout << dq.pop_front() << '\n';
			else if (opt[5] == 'a') cout << dq.pop_back()  << '\n';
		}
		else if (opt[0] == 's') cout << dq.size()  << '\n';
		else if (opt[0] == 'e') cout << dq.empty() << '\n';
		else if (opt[0] == 'f') cout << dq.front() << '\n';
		else if (opt[0] == 'b') cout << dq.back()  << '\n';
	}

	return 0;
}
