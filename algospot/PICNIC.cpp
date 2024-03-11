#include <iostream>
#include <cstring>

using namespace std;

int C, n, m;
bool are_friends[10][10];

int count_pairs(bool taken[10])
{
    int answer = 0;
    int first_free = -1;
    for (int i = 0; i < n; ++i)
    {
        if (!taken[i])
        {
            first_free = i;
            break;
        }
    }
    if (first_free == -1) return 1;
    for (int next_free = first_free + 1; next_free < n; ++next_free)
    {
        if (!taken[next_free] && are_friends[first_free][next_free])
        {
            taken[first_free] = taken[next_free] = 1;
            answer += count_pairs(taken);
            taken[first_free] = taken[next_free] = 0;
        }
    }
    return answer;
}

int main()
{
    cin >> C;
    for (int test_case = 1; test_case <= C; ++test_case)
    {
        cin >> n >> m;
        bool taken[10];
        memset(taken, 0, sizeof(taken));
        memset(are_friends, 0, sizeof(are_friends));
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            are_friends[x][y] = are_friends[y][x] = 1;
        }
        cout << count_pairs(taken) << endl;
    }
    return 0;
}
