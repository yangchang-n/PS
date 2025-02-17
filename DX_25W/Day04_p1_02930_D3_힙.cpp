#include <iostream>

using namespace std;

void op_push(int max_heap[], int heap_size, int num)
{
    int size_index = heap_size;
    max_heap[size_index] = num;

    while (size_index > 1)
    {
        if (max_heap[size_index / 2] < max_heap[size_index])
        {
            int temp = max_heap[size_index / 2];
            max_heap[size_index / 2] = max_heap[size_index];
            max_heap[size_index] = temp;

            size_index /= 2;
        }
        else break;
    }
        
    return;
}

void op_pop(int max_heap[], int heap_size)
{
    int parent = 1, left = 2, right = 3;
    
    if (max_heap[1] != 0)
    {
        cout << max_heap[1] << ' ';
        max_heap[1] = max_heap[heap_size];
        max_heap[heap_size] = 0;
        heap_size--;

        while (left <= 100000 && right <= 100000)
        {
            if (max_heap[left] >= max_heap[right] && max_heap[left] > max_heap[parent])
            {
                int temp = max_heap[left];
                max_heap[left] = max_heap[parent];
                max_heap[parent] = temp;

                parent = left;
                left = 2 * parent;
                right = 2 * parent + 1;
            }
            else if (max_heap[left] < max_heap[right] && max_heap[right] > max_heap[parent])
            {
                int temp = max_heap[right];
                max_heap[right] = max_heap[parent];
                max_heap[parent] = temp;

                parent = right;
                left = 2 * parent;
                right = 2 * parent + 1;
            }
            else break;
        }
    }
    else cout << "-1 ";

    return;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
        int max_heap[100001] = {0};
        int heap_size = 0;
        
        int N;
        cin >> N;

        cout << '#' << test_case << ' ';

        for (int i = 0; i < N; ++i)
        {
            int cmd, input_num;
            cin >> cmd;

            if (cmd == 1)
            {
                cin >> input_num;
                heap_size++;
                op_push(max_heap, heap_size, input_num);
            }
            else if (cmd == 2)
            {
                op_pop(max_heap, heap_size);
            }
        }

        cout << '\n';
	}
    
	return 0;
}
