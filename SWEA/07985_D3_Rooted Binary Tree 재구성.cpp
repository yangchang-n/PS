#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
        int K;
        cin >> K;

        int list_len = 1;
        for (int i = 1; i <= K; ++i) list_len *= 2;

        int num_list[list_len + 1] = {0};

        for (int i = 1; i < list_len; ++i)
        {
            int div_check = list_len / 2;

            while (div_check != 1)
            {
                if (i % div_check == 0) break;
                else div_check /= 2;
            }
            
            cin >> num_list[(((i / div_check) + 1) / 2) + (list_len / (div_check * 2)) - 1];
        }

        int new_line = 2;

        cout << '#' << test_case << ' ';
        for (int i = 1; i < list_len; ++i)
        {
            if (i % new_line == 0)
            {
                cout << '\n';
                new_line *= 2;
            }
            cout << num_list[i] << ' ';
        }
        cout << '\n';
	}
    
	return 0;
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
//               8
//       4                 12
//   2       6       10          14
// 1   3   5   7   9    11    13    15

// 2   4   6   8   10   12    14    16
// 1   2   3   4   5    6     7     8
// div_check으로 나눈다음 1 더하고 2로 나누기 : 이게 순서
// (list_len / (div_check * 2)) - 1 : 근데 이거 이후부터
