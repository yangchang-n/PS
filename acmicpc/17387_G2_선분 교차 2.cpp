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

bool on_segment(const Point& A, const Point& B, const Point& P)
{
    return min(A.x, B.x) <= P.x && P.x <= max(A.x, B.x)
        && min(A.y, B.y) <= P.y && P.y <= max(A.y, B.y);
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
    else if (c1 == 0 && c2 < 0)
    {
        if (ccw(p1, p2, p3) == 0 && on_segment(p1, p2, p3)) contact = true;
        if (ccw(p1, p2, p4) == 0 && on_segment(p1, p2, p4)) contact = true;
    }
    else if (c2 == 0 && c1 < 0)
    {
        if (ccw(p3, p4, p1) == 0 && on_segment(p3, p4, p1)) contact = true;
        if (ccw(p3, p4, p2) == 0 && on_segment(p3, p4, p2)) contact = true;
    }
    else if (c2 == 0 && c1 == 0)
    {
        if (on_segment(p1, p2, p3) || on_segment(p1, p2, p4)
         || on_segment(p3, p4, p1) || on_segment(p3, p4, p2)) contact = true;
    }

    cout << (contact ? 1 : 0);

    return 0;
}
