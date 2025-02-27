//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define MAX_N 100010
#define all_range 1, 0, N - 1

using namespace std;

int arr[MAX_N];
int seg_min[4 * MAX_N], seg_max[4 * MAX_N];

void init(int node, int s, int e)
{
    if (s == e) seg_min[node] = seg_max[node] = arr[s];
    else
    {
        int m = (s + e) >> 1;
        init(node << 1, s, m);
        init((node << 1) | 1, m + 1, e);
        seg_min[node] = min(seg_min[node << 1], seg_min[(node << 1) | 1]);
        seg_max[node] = max(seg_max[node << 1], seg_max[(node << 1) | 1]);
    }
}

void update(int node, int s, int e, int ii, int x)
{
    if (s == e) seg_min[node] = seg_max[node] = x;
    else
    {
        int m = (s + e) >> 1;
        if (ii <= m) update(node << 1, s, m, ii, x);
        else update((node << 1) | 1, m + 1, e, ii, x);
        seg_min[node] = min(seg_min[node << 1], seg_min[(node << 1) | 1]);
        seg_max[node] = max(seg_max[node << 1], seg_max[(node << 1) | 1]);
    }
}

int query_max(int node, int s, int e, int l, int r)
{
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg_max[node];
    int m = (s + e) >> 1;
    return max(query_max(node << 1, s, m, l, r), query_max((node << 1) | 1, m + 1, e, l, r));
}

int query_min(int node, int s, int e, int l, int r)
{
    if (r < s || e < l) return 1e9 + 1;
    if (l <= s && e <= r) return seg_min[node];
    int m = (s + e) >> 1;
    return min(query_min(node << 1, s, m, l, r), query_min((node << 1) | 1, m + 1, e, l, r));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("sample_in.txt", "r", stdin);

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case)
    {
        int N, Q;
        cin >> N >> Q;

        for (int i = 0; i < N; ++i) cin >> arr[i];

        init(all_range);

        cout << '#' << test_case;
        for (int i = 0; i < Q; ++i)
        {
            int opt, num1, num2;
            cin >> opt >> num1 >> num2;
            if (opt == 0) update(all_range, num1, num2);
            else cout << ' ' << query_max(all_range, num1, num2 - 1) - query_min(all_range, num1, num2 - 1);
        }
        cout << '\n';
    }

    return 0;
}
