#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define ll long long
#define ull long long
#define ld long double
#define TEST puts("Zero")

#define MOD 1000000007
#define MAXN 10
#define EPS 1e-8

using namespace std;

struct Point {
    double x, y;
    Point(){};
    Point(double x, double y):x(x),y(y) {}
    Point ort() { return Point(-y, x); }
};

int C[MAXN][MAXN];
Point P[MAXN];
int V[MAXN];

Point operator- (const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator+ (const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator* (double r, const Point &b) { return Point(r*b.x, r*b.y); }
double operator* (const Point &a, const Point &b) { return a.x*b.x + a.y*b.y; }
bool operator== (const Point &a, const Point &b) { return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS; }
bool operator< (const Point &a, const Point &b) {
    if (abs(a.x - b.x) < EPS) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

Point intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
    Point ab = b - a, cd = d - c, ac = c - a;
    double r = ac*cd.ort();
    r /= ab*cd.ort();
    return a + r*ab;
}

bool parallel(const Point &a, const Point &b, const Point &c, const Point &d) {
    Point ab = b - a, cd = d - c, ac = c - a;
    return abs(ab*cd.ort()) < EPS;
}

bool inSegment(const Point &a, const Point &b, const Point &x) {
    Point ax = x - a, bx = x - b;
    return abs(ax*bx.ort()) < EPS && ax*bx < EPS;
}

bool isCity(const Point &a, int n) {
    for (int i = 0; i < n; i++) {
        if (a == P[i]) return true;
    }
    return false;
}

int main(int nargs, char **args) {
    int n, c, casos = 1;
    while (scanf("%d%d", &n, &c)) {
        if (n + c == 0) break;
        for (int i = 0, x, y; i < n; i++) {
            scanf("%d%d", &x, &y);
            P[i] = Point(x, y);
        }

        for (int i = 0; i < n; i++) {
            for (int  j = 0; j < n; j++) {
                scanf("%d", &C[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            V[i] = i;
        }

        int ans = (1<<30), pa;
        do {
            pa = 0;
            for (int i = 0; i < n; i++) {
                pa += C[V[i]][V[(i + 1)%n]];
            }

            map <Point, set <int> > mp;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    Point a = P[V[i]], b = P[V[(i + 1)%n]];
                    Point c = P[V[j]], d = P[V[(j + 1)%n]];
                    if (parallel(a, b, c, d)) continue;
                    Point x = intersect(a, b, c, d);
                    if (inSegment(a, b, x) && !isCity(x, n)) {
                        mp[x].insert(i);
                        mp[x].insert(j);
                    }
                }
            }

            for (map<Point, set<int> >::iterator it = mp.begin(); it != mp.end(); it++) {
                int k = it->se.size();
                pa += c*(k*(k-1))/2;
            }

            ans = min(pa, ans);
        } while (next_permutation(V + 1, V + n));
        printf("%d. %d\n", casos++, ans);
    }

    return 0;
}
