#include <iostream>
 
using namespace std;
 
int stk[100000];
int pos;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     
    int T;
    cin >> T;
     
    for (int tc = 1; tc <= T; ++tc)
    {
        int K, n;
        cin >> K;
         
        pos = 0;
        for (int i = 0; i < K; ++i)
        {
            cin >> n;
 
            if (n == 0) pos--;
            else stk[pos++] = n;
        }
 
        int ans = 0;
        for (int i = 0; i < pos; ++i) ans += stk[i];
 
        cout << '#' << tc << ' ' << ans << '\n';
    }
         
    return 0;
}
