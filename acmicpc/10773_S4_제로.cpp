#include <iostream>

using namespace std;

int stk[100000];
int pos = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int K, n;
    cin >> K;
    
    for (int i = 0; i < K; ++i)
    {
        cin >> n;
        
        if (n == 0) pos--;
        else stk[pos++] = n;
    }
    
    int ans = 0;
    for (int i = 0; i < pos; ++i) ans += stk[i];
    
    cout << ans;
    
    return 0;
}
