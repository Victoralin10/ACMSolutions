#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

clock_t _inicio = clock();

typedef long long Long;
typedef long double Double;
typedef vector <int> vInt;
typedef pair <int, int> Pair;


struct Point {
    Long x, y;
    Point(){}
    Point(Long x, Long y):x(x), y(y){}
    Long mod2() {
        return x*x + y*y;
    }
};

Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Long operator *(const Point &a, const Point &b) { return a.x*b.x + a.y*b.y; }
Long cross(const Point &a, const Point &b) { return a.x*b.y - a.y*b.x; }
Long cross(const Point &a, const Point &b, const Point &c) { return cross(a - b, c - b); }

Long d2(const Point &a, const Point &b) { return (a - b).mod2(); }

Point r;
bool operator <(const Point &a, const Point &b) {
    Long ar = cross(a, r, b);
    return (ar==0?d2(r, a)<d2(r, b):ar>0);
}

vector <Point> convexHull(vector <Point> &points) {
    if (SZ(points) < 3) {
        return points;
    }

    r = *(min_element(all(points), [](const Point &a, const Point &b) {
        return (a.y==b.y?a.x<b.x:a.y<b.y);
    }));
    sort(all(points));

    vector <Point> ans;
    int i = 0, s;
    while (i < SZ(points)) {
        s = SZ(ans);
        if (s > 1 && cross(points[i], ans[s-1], ans[s-2]) <= 0) {
            ans.pop_back();
        } else {
            ans.push_back(points[i++]);
        }
    }

    return ans;
}

int K[100005];

int main(int nargs, char **args) {
    int n, m, x, y;
    cin >> n >> m;

    vector <Point> a(n), b(m);
    REP(i, n) {
        cin >> a[i].x >> a[i].y;
    }
    REP(i, m) {
        cin >> b[i].x >> b[i].y;
    }

    a = convexHull(a);
    b = convexHull(b);

    if (a.size() != b.size()) {
        puts("NO");
        return 0;
    }

    int l = a.size();
    vector <pair <Long, Long > > ta, tb;
    REP(i, l) {
        Point pa = a[i], pb = a[(i+1)%n], pc = a[(i+2)%n];
        ta.push_back({cross(pc, pb, pa), (pa - pb)*(pc - pb)});
        pa = b[i], pb = b[(i+1)%n], pc = b[(i+2)%n];
        tb.push_back({cross(pc, pb, pa), (pa - pb)*(pc - pb)});
    }

    REP(i, l) {
        tb.push_back(tb[i]);
    }

    int i = 0, j = K[0] = -1;
    while (i < l) {
        while (j != -1 && ta[i] != ta[j]) j = K[j];
        K[++i] = ++j;
    }

    int lb = tb.size();
    bool ok = 0;
    i = 0, j = 0;
    while (i < lb) {
        while (j != -1 && tb[i] != ta[j]) j = K[j];
        j++, i++;
        if (j == l) {
            ok = 1;
            break;
        }
    }
    puts(ok?"YES":"NO");

    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
