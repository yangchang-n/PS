#include <iostream>

using namespace std;

int N;
int node[26][2];

void cout_preorder(int n)
{
	if (n == -1) return;
	char c = n + 'A';

	cout << c;
	cout_preorder(node[n][0]);
	cout_preorder(node[n][1]);
}

void cout_inorder(int n)
{
	if (n == -1) return;
	char c = n + 'A';

	cout_inorder(node[n][0]);
	cout << c;
	cout_inorder(node[n][1]);
}

void cout_postorder(int n)
{
	if (n == -1) return;
	char c = n + 'A';

	cout_postorder(node[n][0]);
	cout_postorder(node[n][1]);
	cout << c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 2; ++j) node[i][j] = -1;
	}

	for (int i = 0; i < N; ++i)
	{
		char P, L, R;
		cin >> P >> L >> R;

		int p = P - 'A';
		int l = L - 'A';
		int r = R - 'A';

		if (l != -19) node[p][0] = l;
		if (r != -19) node[p][1] = r;
	}

	cout_preorder(0);
	cout << '\n';
	cout_inorder(0);
	cout << '\n';
	cout_postorder(0);
	
	return 0;
}
