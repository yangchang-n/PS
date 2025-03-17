#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> cnt(9, 0);
    char num[8];
    cin.getline(num, 8);
    
    for (int i = 0; num[i] != '\0'; ++i)
    {
        if (num[i] == '9') cnt[6]++;
        else cnt[num[i] - '0']++;
    }
    
    cnt[6] -= cnt[6] / 2;
    int ans = *max_element(cnt.begin(), cnt.end());
    
    cout << ans;
    
    return 0;
}
