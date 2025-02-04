#include<iostream>

int sequence[100];
int seq_cnt = 0;

using namespace std;

void in_order(int current_node, int max_node)
{
    if (current_node > max_node) return;
    in_order(current_node * 2, max_node);
    sequence[seq_cnt] = current_node;
    seq_cnt++;
    in_order(current_node * 2 + 1, max_node);
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
	sequence[100] = {0};
	seq_cnt = 0;
	
	int N;
	cin >> N;
	
	char tree[N + 2];
	in_order(1, N);
	
	for (int i = 0; i < N; ++i)
	{
	    int node_num, left, right;
	    char value;
	
	    cin >> node_num >> value;
	    if (cin.peek() != '\n') cin >> left;
	    if (cin.peek() != '\n') cin >> right;
	
	    tree[node_num] = value;
	}
	
	cout << '#' << test_case << ' ';
	
	for (int i = 0; i < N; ++i)
	{
	    cout << tree[sequence[i]];
	}
	
	cout << '\n';
	}
	
	return 0;
}
