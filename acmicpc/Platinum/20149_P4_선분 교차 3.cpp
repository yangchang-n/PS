#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

struct Point { ld x, y; };

int ccw(const Point& A, const Point& B, const Point& C)
{
    ld cross = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
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

    int c1 = ccw(p1, p2, p3);
    int c2 = ccw(p1, p2, p4);
    int c3 = ccw(p3, p4, p1);
    int c4 = ccw(p3, p4, p2);

    if (c1 * c2 < 0 && c3 * c4 < 0)
    {
        ld dx1 = p2.x - p1.x;
        ld dy1 = p2.y - p1.y;
        ld dx2 = p4.x - p3.x;
        ld dy2 = p4.y - p3.y;

        ld det = dx1 * dy2 - dy1 * dx2;
        ld t = ((p3.x - p1.x) * dy2 - (p3.y - p1.y) * dx2) / det;

        Point ip;
        ip.x = p1.x + t * dx1;
        ip.y = p1.y + t * dy1;

        cout << "1\n" << fixed << setprecision(12) << ip.x << ' ' << ip.y;
    }
    else
    {
        vector<Point> pts;
        if (c1 == 0 && on_segment(p1, p2, p3)) pts.push_back(p3);
        if (c2 == 0 && on_segment(p1, p2, p4)) pts.push_back(p4);
        if (c3 == 0 && on_segment(p3, p4, p1)) pts.push_back(p1);
        if (c4 == 0 && on_segment(p3, p4, p2)) pts.push_back(p2);

        if (!pts.empty()) cout << "1\n";
        else
        {
            cout << "0\n";
            return 0;
        }

        if (pts.size() == 1)
        {
            cout << fixed << setprecision(12) << pts[0].x << ' ' << pts[0].y;
        }
        else if (pts.size() == 2 && pts[0].x == pts[1].x && pts[0].y == pts[1].y)
        {
            cout << fixed << setprecision(12) << pts[0].x << ' ' << pts[0].y;
        }
    }

    return 0;
}
