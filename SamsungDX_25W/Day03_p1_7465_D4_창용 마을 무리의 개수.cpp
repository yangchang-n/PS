#include <iostream>

using namespace std;

int path_comp(int parent[], int a)
{
    if(parent[a] == a) return a;
    else parent[a] = path_comp(parent, parent[a]);
    return parent[a];
}

void make_union(int parent[], int a, int b)
{
    int pa = path_comp(parent, a);
    int pb = path_comp(parent, b);
    if(pa != pb) parent[pb] = pa;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T;
	cin >> T;

	for(int test_case = 1; test_case <= T; ++test_case)
	{
        int N, M;
        cin >> N >> M;

        int parent[N + 1];

        for(int i = 1; i <= N; ++i) parent[i] = i;

        for(int i = 0; i < M; ++i)
        {
            int a, b;
            cin >> a >> b;
            make_union(parent, a, b);
        }

        int count = 0;
        for(int i = 1; i <= N; ++i)
        {
            if(path_comp(parent, i) == i) count++;
        }

        cout << '#' << test_case << ' ' << count << '\n';
	}
    
	return 0;
}
