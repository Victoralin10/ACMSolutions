#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef vector <vInt> vvInt;
typedef vector <string> vStr;
typedef pair <int, int> Pair;
typedef vector <pair <int, int> > vPair;

#define MAXN 100005

struct Point {
    double x, y;
    Point(){}
    Point(double x, double y):x(x), y(y) {}
};

int n, A[MAXN], B[MAXN];
Long C[MAXN];
Point L[MAXN], I[MAXN];


Point operator -(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

double operator *(const Point &a, const Point &b) {
    return a.x*b.x + a.y*b.y;
}

double cross(Point a, Point b) {
    return a.x*b.y - a.y*b.x;
}

double cross(Point a, Point b, Point c) {
    return cross(a - b, c - b);
}

Point intersectLines(Point &a, Point &b) {
    double x = -(a.y - b.y)/(a.x - b.x);
    return Point(x, a.y*x + a.y);
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    C[n-1] = 0;
    int ch_len = 1;
    L[0] = Point(A[n-1], 0);
    for (int i = n-2, l = 0; i >= 0; i--) {
        if (l < 2 || I[1].x <= B[i]) {
            C[i] = L[0]*Point(B[i], 1);
        } else {
            int lo = 0, hi = l + 1, mid;
            while (hi - lo > 1) {
                mid = (hi + lo)/2;
                if (I[mid].x <= B[i]) hi = mid;
                else lo = mid;
            }
            C[i] = L[lo]*Point(B[i], 1);
        }
        Point np(A[i], C[i]);
        while (l > 1 && cross(np, L[l - 1], L[l - 2]) >= 0) {
            l--;
        }
        L[l] = np;
        I[l++] = intersectLines(np, L[l - 1]);
    }
    for (int i = 0; i < n; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
    cout << C[0] << endl;

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
