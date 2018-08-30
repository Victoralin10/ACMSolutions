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
typedef vector <int> vInt;
typedef pair <int, int> Pair;

struct Point {
    int r, c;
    Point(){}
    Point(int r, int c):r(r), c(c){}
};

struct Line {
    int rc, lo, hi;
    Line(){}
    Line(int rc, int lo, int hi):rc(rc), lo(lo), hi(hi){}
};

void addMirror(auto &row, auto &col, auto &type, int r, int c, int t) {
    row[r].push_back(c);
    col[c].push_back(r);
    type[{r, c}] = t;
}

bool isOuter(int r, int c, int R, int C) {
    return r < 1 || c < 1 || r > R || c > C;
}

int nextValue(bool gt, int val, vector <int> &v, int defaultMax) {
    if (gt) {
        auto it = upper_bound(all(v), val);
        if (it == v.end()) {
            return defaultMax;
        }
        return *it;
    }

    auto it = lower_bound(all(v), val);
    if (it == v.begin()) {
        return 0;
    }
    it--;
    return *it;
}        

Point nextPoint(Point &current, int dir, auto &rows, auto &cols, int R, int C) {
    if (dir%2 == 0) {
        int nc = nextValue(dir==0, current.c, rows[current.r], C + 1);
        return Point(current.r, nc);
    }

    int nr = nextValue(dir==1, current.r, cols[current.c], R + 1);
    return Point(nr, current.c);
}

vector <Point> computePath(Point start, int dir, int R, int C, auto &rows, auto &cols, auto &type) {
    vector <Point> ans;
    ans.push_back(start);
    Point current = start, next;
    do {
        next = nextPoint(current, dir, rows, cols, R, C);
        dir += type[{next.r, next.c}]*(dir%2==0?-1:1);
        dir = (dir + 4)%4;
        current = next;
        ans.push_back(current);
    } while (!isOuter(current.r, current.c, R, C));
    return ans;
}

void sortMapVector(auto &mp) {
    for (auto &x: mp) {
        sort(x.second.begin(), x.second.end());
    }
}

#define MAXN 1000006

int F[MAXN];

void update(int px, int val) {
    assert(px > 0);
    while (px < MAXN) {
        F[px] += val;
        px += px&(-px);
    }
}

int query(int px) {
    if (px < 1) return 0;
    px = min(px, MAXN - 1);

    int ans = 0;
    while (px) {
        ans += F[px];
        px -= px&(-px);
    }
    return ans;
}

int query(int a, int b) {
    if (a > b) return 0;
    return query(b) - query(a - 1);
}

Long countIntersections(vector <Line> &h, vector <Line> &v, int &fr, int &fc) {
    Long ans = 0;
    sort(all(h), [](Line a, Line b) { return a.rc < b.rc || (a.rc == b.rc && a.lo < b.lo); });
    sort(all(v), [](Line a, Line b) { return a.lo < b.lo; });
    clr(F, 0);

    priority_queue <pair<int, int> > endQueue;
    auto it = v.begin();
    for (Line &line: h) {
        while (it != v.end() && it->lo < line.rc) {
            update(it->rc, 1);
            endQueue.push({it->hi, it->rc});
            it++;
        }
        while (!endQueue.empty() && endQueue.top().first <= line.rc) {
            update(endQueue.top().second, -1);
            endQueue.pop();
        }
        int ni = query(line.lo + 1, line.hi - 1);
        if (ni && line.rc <= fr) {
            int lo = line.lo, hi = line.hi - 1, mid;
            while (hi - lo > 1) {
                mid = (hi + lo)>>1;
                (query(line.lo + 1, mid)?hi:lo) = mid;
            }
            fr = line.rc;
            fc = min(fc, hi);
        }
        ans += ni;
    }

    return ans;
}

void pathToLines(auto &points, auto &h, auto &v) {
    int  rc, lo, hi;
    REPR(i, 1, SZ(points)) {
        if ((i&1)) {
            rc = points[i].r;
            lo = min(points[i-1].c, points[i].c);
            hi = max(points[i-1].c, points[i].c);
            h.push_back(Line(rc, lo, hi));
        } else {
            rc = points[i].c;
            lo = min(points[i-1].r, points[i].r);
            hi = max(points[i-1].r, points[i].r);
            v.push_back(Line(rc, lo, hi));
        }
    }
}


int main(int nargs, char **args) {
    int R, C, m, n, caso = 1, r, c;
    while (scanf("%d%d%d%d", &R, &C, &m, &n) == 4) {
        map <int, vector <int>> rowPoints, colPoints;
        map <pair<int, int>, int> type;
        REP(i, m) {
            scanf("%d%d", &r, &c);
            addMirror(rowPoints, colPoints, type, r, c, 1);
        }
        REP(i, n) {
            scanf("%d%d", &r, &c);
            addMirror(rowPoints, colPoints, type, r, c, -1);
        }

        sortMapVector(rowPoints);
        sortMapVector(colPoints);

        vector <Point> goPoints = computePath(Point(1, 0), 0, R, C, rowPoints, colPoints, type);
        Point lastPoint = goPoints[SZ(goPoints) - 1];
        if (lastPoint.r == R && lastPoint.c == C + 1) {
            printf("Case %d: 0\n", caso++);
            continue;
        }

        vector <Point> backPoints = computePath(Point(R, C + 1), 2, R, C, rowPoints, colPoints, type);

        int fr = R + 1, fc = C+1;
        vector <Line> v[4];
        pathToLines(goPoints, v[0], v[1]);
        pathToLines(backPoints, v[2], v[3]);

        Long ans = countIntersections(v[0], v[3], fr, fc);
        ans += countIntersections(v[2], v[1], fr, fc);

        if (ans == 0) {
            printf("Case %d: impossible\n", caso++);
        } else {
            cout << "Case " << (caso++) << ": " << ans << " " << fr << " " << fc << endl;
        }
    }

    cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
