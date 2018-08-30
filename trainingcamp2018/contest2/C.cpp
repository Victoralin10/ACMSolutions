#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define MAXN 1003

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef vector <vInt> vvInt;
typedef vector <string> vStr;
typedef pair <int, int> Pair;
typedef vector <pair <int, int> > vPair;

struct Point {
    double x, y;
    Point(){}
    Point(double x, double y):x(x), y(y){}
    void read() {
        cin >> x >> y;
    }
    double mod() {
        return sqrt(x*x + y*y);
    }
    Point ort() {
        return Point(-y, x);
    }
};

Point P[MAXN];

double operator *(const Point &a, const Point &b) {
    return a.x*b.x + a.y*b.y;
}

Point operator -(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        P[i].read();
    }

    double ans = 1e20, par;
    for (int i = 0; i < n; i++) {
        Point a = P[i], b = P[(i+1)%n], c = P[(i+2)%n];

        par = (b - a)*(c - b).ort();
        par /= (c - a).mod();
        ans = min(ans, par/2.0);
    }
    printf("%.10f\n", ans);

    //fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
