#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;

        vector<vector<int>> agents_info(N, vector<int>(3));

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cin >> agents_info[i][j];
            }
        }

        if (N < 3)
        {
            cout << '#' << test_case << " -1" << endl;
            continue;
        }

        int answer = 0;
        vector<int> stats_count(3, 0);
        vector<vector<int>> agents_diff(N, vector<int>(3));

        for (int agent_num = 0; agent_num < N; ++agent_num)
        {
            int max_stat = *max_element(agents_info[agent_num].begin(), agents_info[agent_num].end());
            int sum_stat = accumulate(agents_info[agent_num].begin(), agents_info[agent_num].end(), 0);
            answer += sum_stat - max_stat;

            for (int i = 0; i < 3; ++i)
            {
                if (agents_info[agent_num][i] == max_stat)
                {
                    stats_count[i] += 1;
                }
                agents_diff[agent_num][i] = (max_stat - agents_info[agent_num][i]);
            }
        }

        vector<int> is_zero, is_one;
        for (int j = 0; j < 3; ++j)
        {
            if (stats_count[j] == 0)
                is_zero.push_back(j);
            else if (stats_count[j] == 1)
                is_one.push_back(j);
        }

        int stat_to_fix = 1e6;

        if (is_zero.size() + is_one.size() == 2)
        {
            vector<int> index_to_fix(is_zero);
            index_to_fix.insert(index_to_fix.end(), is_one.begin(), is_one.end());

            for (int k = 0; k < N; ++k)
            {
                for (int l = 0; l < N; ++l)
                {
                    if (k != l)
                    {
                        stat_to_fix = min(stat_to_fix, agents_diff[k][index_to_fix[0]] + agents_diff[l][index_to_fix[1]]);
                        if (stat_to_fix == 0)
                            break;
                    }
                }
                if (stat_to_fix == 0)
                    break;
            }
        }
        else if (is_zero.size() == 1 && is_one.empty())
        {
            for (int m = 0; m < N; ++m)
            {
                stat_to_fix = min(stat_to_fix, agents_diff[m][is_zero[0]]);
                if (stat_to_fix == 0)
                    break;
            }
        }
        else
        {
            stat_to_fix = 0;
        }

        answer += stat_to_fix;
        cout << '#' << test_case << ' ' << answer << endl;
    }

    return 0;
}
