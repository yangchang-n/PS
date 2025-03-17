#include <iostream>

using namespace std;

int num[1'000'001] = {};
int n, x, tmp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        num[tmp]++;
    }
    
    cin >> x;
    
    if (x <= 2 || x == 2'000'000)
    {
        cout << 0;
        return 0;
    }
    
    int cnt = 0;
    int min_lim, max_lim;
    
    max_lim = (x + 1) / 2;
    if (x <= 1'000'001) min_lim = 1;
    else min_lim = x - 1'000'000;
    
    for (int i = min_lim; i < max_lim; ++i)
    {
        if (num[i] && num[x - i]) cnt++;
    }

    cout << cnt;
    
    return 0;
}
