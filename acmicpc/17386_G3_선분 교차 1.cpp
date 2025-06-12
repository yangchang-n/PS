#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

struct Point { ll x, y; };

int ccw(const Point& A, const Point& B, const Point& C)
{
    ll cross = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    if (cross > 0) return  1;
    if (cross < 0) return -1;
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    int c1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int c2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    bool contact = false;
    if (c1 < 0 && c2 < 0) contact = true;

    cout << (contact ? 1 : 0) << '\n';

    return 0;
}
