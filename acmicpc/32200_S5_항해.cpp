#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int sw[40'010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, X, Y;
    cin >> N >> X >> Y;
    for (int i = 0; i < N; ++i) cin >> sw[i];
    
    ll an1 = 0;
    ll an2 = 0;
    ll cnt = 0;
    ll lft = 0;
    ll avl = 0;
    for (int i = 0; i < N; ++i)
    {
        cnt = sw[i] / X;
        lft = sw[i] % X;
        avl = cnt * (Y - X);
        an1 += cnt;
        an2 += max(lft - avl, 0LL);        
    }
    
    cout << an1 << '\n' << an2;
    
    return 0;
}
