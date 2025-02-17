#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> color_index =
{
    {"red", 0}, {"orange", 1}, {"yellow", 2},
    {"green", 3}, {"blue", 4}, {"purple", 5}
};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        string color1, color2;
        cin >> color1 >> color2;

        int idx1 = color_index[color1];
        int idx2 = color_index[color2];

        if (idx1 == idx2)
        {
            cout << "E\n";
        }
        else if ((abs(idx1 - idx2) == 1) || (abs(idx1 - idx2) == 5))
        {
            cout << "A\n";
        }
        else if (abs(idx1 - idx2) == 3)
        {
            cout << "C\n";
        }
        else
        {
            cout << "X\n";
        }
    }
    
    return 0;
}
