/**
* Title:            2613 - Will Indiana Jones Get There?
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1001

using namespace std;

struct Point {
    double x, y;
    Point(){}
    Point(double x, double y):x(x), y(y){}

    Point ort() { return Point(-y, x); }
    double mod2() { return x*x + y*y; }
    double mod() { return sqrt(mod2()); }
    void print() {
        printf("%.2f %.2f", x, y);
    }
};

Point operator+ (const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator- (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

double operator* (const Point &a, const Point &b) {
    return a.x*b.x + a.y*b.y;
}

Point operator* (const Point &a, double k) {
    return Point(a.x*k, a.y*k);
}

Point operator* (double k, const Point &a) {
    return Point(a.x*k, a.y*k);
}

bool inInterval(const Point &a, const Point &b, const Point &c) {
    return ((a - b)*(c - a).ort() == 0) && ((c - a)*(c - b) <= 0);
}

Point proyeccion(const Point &a, const Point &b, const Point &c) {
    Point u = b - a;
    return a + (((c - a)*u)/(u*u))*u;
}

double distance(const Point &a, const Point &b, const Point &c) {
    Point p = proyeccion(a, b, c);
    if (inInterval(a, b, p)) {
        return (c - p).mod();
    }

    return min((c - a).mod(), (c - b).mod());
}

Point interseccion(const Point &a, const Point &b, const Point &c,
    const Point &d) {

    Point u1 = (b - a), u2 = (d - c);
    return a + (((c - a)*u2.ort())/(u1*u2.ort()))*u1;
}

pair <Point, Point> lineas[MAXN];

double distLL(int a, int b) {
    Point p = interseccion(lineas[a].first, lineas[a].second,
        lineas[b].first, lineas[b].second);

    if (inInterval(lineas[a].first, lineas[a].second, p) &&
            inInterval(lineas[b].first, lineas[b].second, p)) {

        return 0.0;
    }

    double ans = (1LL<<40);
    ans = min(ans, distance(lineas[a].first, lineas[a].second, lineas[b].first));
    ans = min(ans, distance(lineas[a].first, lineas[a].second, lineas[b].second));
    ans = min(ans, distance(lineas[b].first, lineas[b].second, lineas[a].first));
    ans = min(ans, distance(lineas[b].first, lineas[b].second, lineas[a].second));

    return ans;
}

int H[MAXN];
int F(int x) { return x == H[x]?x : H[x] = F(H[x]); }
void U(int x, int y) { H[F(x)] = F(y); }

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    int n, x, y, l;
    while (scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &x, &y, &l);
            if (l >= 0) {
                lineas[i] = make_pair(Point(x,y), Point(x + l, y));
            } else {
                lineas[i] = make_pair(Point(x,y), Point(x, y - l));
            }
            H[i] = i;
        }

        vector < pair <double, pair <int, int> > > tablas;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                double d = distLL(i, j);
                tablas.push_back(make_pair(d, make_pair(i, j)));
            }
        }

        sort(tablas.begin(), tablas.end());

        double ans = 0;
        vector < pair <double, pair <int, int> > >::iterator it;
        for (it = tablas.begin(); it != tablas.end() && F(0) != F(1); it++) {
            ans = it->first;
            U(it->second.second, it->second.first);
        }

        printf("%.2f\n", ans);
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
