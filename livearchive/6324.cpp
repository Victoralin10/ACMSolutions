#include<bits/stdc++.h>
#define sc(x) scanf("%d", &(x))
#define endl "\n"
#define FN(i, n) for(int (i) = 0; (i) < (n) ; (i)++)
using namespace std;


#define _TYPE long double
#define EPS 1e-9
const _TYPE PI = acos(-1.0);

struct Point {
    _TYPE x, y;
    Point(){}
    Point(_TYPE x, _TYPE y):x(x), y(y){}

    Point ort() { return Point(-y, x); }
    _TYPE mod2() { return x*x + y*y; }
    _TYPE mod() { return sqrt(mod2()); }
    Point unit() {
        _TYPE md = mod();
        return Point(x/md, y/md);
    }
    _TYPE ang() {
        return atan2(y, x);
    }
};

Point operator+ (const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator- (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

_TYPE operator* (const Point &a, const Point &b) {
    return a.x*b.x + a.y*b.y;
}

Point operator* (const Point &a, _TYPE k) {
    return Point(a.x*k, a.y*k);
}

Point operator* (_TYPE k, const Point &a) {
    return Point(a.x*k, a.y*k);
}

Point operator/ (const Point &a, _TYPE k) {
    return Point(a.x/k, a.y/k);
}

// Is Point c in segment ab?
bool inSegment(const Point &a, const Point &b, const Point &c) {
    return ((a - b)*(c - a).ort() == 0) && ((c - a)*(c - b) <= 0);
}

// Point c projection on line passing through a, b.
Point projection(const Point &a, const Point &b, const Point &c) {
    Point u = b - a;
    return a + (((c - a)*u)/(u*u))*u;
}

// Point c distance to segment ab
_TYPE distance(const Point &a, const Point &b, const Point &c) {
    Point p = projection(a, b, c);
    if (inSegment(a, b, p)) {
        return (c - p).mod();
    }

    return min((c - a).mod(), (c - b).mod());
}

// Intersection of lines passing through ab and cd
Point intersection(const Point &a, const Point &b, const Point &c,
    const Point &d) {

    Point u1 = (b - a), u2 = (d - c);
    return a + (((c - a)*u2.ort())/(u1*u2.ort()))*u1;
}

// Angle of ւabc
_TYPE angle(const Point &b, const Point &a, const Point &c) {
    _TYPE a1 = (a - b).ang(), a2 = (c - b).ang();
    if (a1 < 0) {
        a1 += 2*PI;
    }
    if (a2 < 0) {
        a2 += 2*PI;
    }

    return a1 - a2;
}
int n;

int main() {
  int tc;
  sc(tc);
  FN (itc, tc) {
    sc(n);
    _TYPE res = 0;
    FN (i, n) {
      int x1, y1, x2, y2;
      sc(x1);
      sc(y1);
      sc(x2);
      sc(y2);
      Point p1 = Point(x1, y1);
      _TYPE a1 = p1.ang();
      Point p2 = Point(x2, y2);
      _TYPE a2 = p2.ang();

      _TYPE dif = abs(a1 - a2);
      dif = min(2.0*PI - dif, dif);
      res += dif;
    }
    res /= (2.0*PI);
    printf("%.5f\n", (double)res);

  }
}
