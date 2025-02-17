#include <iostream>

using namespace std;
typedef long long ll;

ll bin_search(ll num)
{
    ll left = 1, right = 2e9, result = -1;
    
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        ll total = mid * (mid + 1) / 2;

        result = mid;
        if (total == num) return result;
        else if (total < num) left = mid + 1;
        else right = mid - 1;
    }

    if (result * (result + 1) / 2 == num) return result;
    else return -1;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
        ll candle_num;
        cin >> candle_num;

        ll answer = bin_search(candle_num);
        
        cout << '#' << test_case << ' ' << answer << '\n';
    }
    
    return 0;
}
