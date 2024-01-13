#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find_index(int num)
{
    int i = 1;
    while (true)
    {
        if (i >= num)
            break;
        num -= i;
        i++;
    }
    return {i, num};
}

int main()
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        vector<int> input_numbers(2);
        cin >> input_numbers[0] >> input_numbers[1];
        sort(input_numbers.begin(), input_numbers.end());

        vector<int> start_index = find_index(input_numbers[0]);
        vector<int> end_index = find_index(input_numbers[1]);

        int row_diff = end_index[0] - start_index[0];
        int col_diff = end_index[1] - start_index[1];

        int answer = row_diff;

        if (col_diff < 0)
            answer -= col_diff;
        else if (col_diff > row_diff)
            answer += (col_diff - row_diff);

        cout << '#' << test_case << ' ' << answer << endl;
    }

    return 0;
}
