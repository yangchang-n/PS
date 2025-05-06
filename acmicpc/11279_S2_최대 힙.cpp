#include <iostream>

using namespace std;

int max_heap[100'010];
int sz = 0;

void heap_push(int num)
{
	max_heap[++sz] = num;

	int tmp = sz;
	while (tmp > 1)
	{
		if (max_heap[tmp] > max_heap[tmp / 2])
		{
			swap(max_heap[tmp], max_heap[tmp / 2]);
			tmp /= 2;
		}
		else break;
	}
}

void heap_pop()
{
	cout << max_heap[1] << '\n';

	max_heap[1] = max_heap[sz--];

	if (!sz) return;

	int p = 1, l = 2, r = 3;
	while (r <= 100'000)
	{
		int nxt = 0;

		if (l <= sz && max_heap[l] > max_heap[p]) nxt = l;
		if (r <= sz && max_heap[r] > max_heap[p] &&
			(!nxt || max_heap[r] > max_heap[l])) nxt = r;
		if (!nxt) break;

		swap(max_heap[nxt], max_heap[p]);

		p = nxt;
		l = p * 2;
		r = p * 2 + 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, num;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> num;

		if (num) heap_push(num);
		else
		{
			if (sz) heap_pop();
			else cout << 0 << '\n';
		}
	}

	return 0;
}
