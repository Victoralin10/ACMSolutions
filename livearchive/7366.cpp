/**
* Title:            7366 - Brocard
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>

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
    _TYPE ang() {
        return atan2(y, x);
    }
    Point unit() {
        _TYPE md = mod();
        return Point(x/md, y/md);
    }
    void scan() {
        cin >> x >> y;
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

Point operator* (_TYPE k, const Point &a) {
    return Point(a.x*k, a.y*k);
}

Point operator/ (const Point &a, _TYPE k) {
    return Point(a.x/k, a.y/k);
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

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    int n;
    cin >> n;

    while (n--) {
        int K;
        Point a, b, c;
        cin >> K;
        a.scan();
        b.scan();
        c.scan();

        long double alpha = 0;
        alpha += 1.0/tan(angle(a, c, b));
        alpha += 1.0/tan(angle(b, a, c));
        alpha += 1.0/tan(angle(c, b, a));
        alpha = atan(1.0/alpha);
        long double betha = angle(b, a, c) - alpha;

        Point ab = b - a;
        long double m = ab.mod()/(1 + tan(alpha)/tan(betha));
        long double n = m*tan(alpha);
        Point ans = a + m*ab.unit() + n*ab.ort().unit();

        printf("%d %.5f %.5f\n", K, (double)ans.x, (double)ans.y);
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
