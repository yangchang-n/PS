#include <iostream>

using namespace std;

int stk[10000];
int pos = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        string opt;
        cin >> opt;
        
        if (opt == "push")
        {
            int tmp;
            cin >> tmp;
            stk[pos++] = tmp;
        }
        else if (opt == "pop")
        {
            if (pos == 0) cout << -1 << '\n';
            else cout << stk[--pos] << '\n';
        }
        else if (opt == "size")
        {
            cout << pos << '\n';
        }
        else if (opt == "empty")
        {
            if (pos == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (opt == "top")
        {
            if (pos == 0) cout << -1 << '\n';
            else cout << stk[pos - 1] << '\n';
        }
    }
    
    return 0;
}
