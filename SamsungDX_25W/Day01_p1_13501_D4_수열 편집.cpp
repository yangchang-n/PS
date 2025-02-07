#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, M, L;
        cin >> N >> M >> L;

        vector<int> sequence(N);
        for (int i = 0; i < N; i++)
        {
            cin >> sequence[i];
        }

        for (int i = 0; i < M; i++)
        {
            char operation;
            cin >> operation;

            if (operation == 'I')
            {
                int idx, num;
                cin >> idx >> num;
                sequence.insert(sequence.begin() + idx, num);
            }
            else if (operation == 'D')
            {
                int idx;
                cin >> idx;
                sequence.erase(sequence.begin() + idx);
            }
            else if (operation == 'C')
            {
                int idx, num;
                cin >> idx >> num;
                sequence[idx] = num;
            }
        }

        int answer = (L < sequence.size()) ? sequence[L] : -1;
        cout << "#" << test_case << " " << answer << endl;
	}
    
	return 0;
}
