#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T;
	cin >> T;

	for(int test_case = 1; test_case <= T; ++test_case)
	{
        long long candle_num;
        cin >> candle_num;
        
        cout << '#' << test_case << ' ';
        if(candle_num == 1)
        {
            cout << 1 << '\n';
            continue;
        }

        long long test_num = candle_num / 2;
        test_num = floor(sqrt(test_num) * 2);

        if(test_num * (test_num + 1) / 2 == candle_num) cout << test_num << '\n';
        else cout << -1 << '\n';
	}
    
	return 0;
}
