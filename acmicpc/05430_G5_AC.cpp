#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

#include <iostream>
#include <queue>

void parse(deque<int>& dq, const string& arr, int n)
{
    if (n == 0) return;

    int num = 0;
    for (int i = 1; i < arr.size() - 1; ++i)
    {
        if (arr[i] != ',') num = num * 10 + (arr[i] - '0');
        else
        {
            dq.push_back(num);
            num = 0;
        }
    }
    dq.push_back(num);
}

int f_p(deque<int>& dq, string& p, int n, bool& flip)
{
    for (int i = 0; i < p.size(); ++i)
    {
        if (p[i] == 'R') flip = flip ? false : true;
        else
        {
            if (!n) return 1;
            else if (!flip) dq.pop_front();
            else if (flip) dq.pop_back();
            n--;
        }
    }

    return 0;
}

int main()
{
    fastIO;

    int T, n;
    string p, arr;

    cin >> T;

    for (int tc = 1; tc <= T; ++tc)
    {
        cin >> p >> n >> arr;
        
        deque<int> dq;
        bool flip = false;

        parse(dq, arr, n);
        int err = f_p(dq, p, n, flip);

        if (err)
        {
            cout << "error\n";
            continue;
        }

        if (dq.empty())
        {
            cout << "[]\n";
            continue;
        }

        cout << '[';
        if (!flip)
        {
            cout << dq[0];
            for (int i = 1; i < dq.size(); ++i) cout << ',' << dq[i];
        }
        else
        {
            cout << dq.back();
            for (int i = dq.size() - 2; i >= 0; --i) cout << ',' << dq[i];
        }
        cout << "]\n";
    }

    return 0;
}
