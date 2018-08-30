#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define ITER(v, it) for(auto it = v.begin(); it != v.end(); it++)
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef pair <int, int> Pair;

const double EPS = 1e-8;
const double PI = acos(-1);

struct Point {
    double x, y;
    int tag = -1;
    Point(){}
    Point(double x, double y):x(x), y(y){}
    double mod2() {
        return x*x + y*y;
    }
    double mod() {
        return sqrt(mod2());
    }
    Point ort() {
        return Point(-y, x);
    }
    double ang() {
        return atan2(y, x);
    }
};

Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }
Point operator *(double k, const Point &a) { return Point(a.x*k, a.y*k); }
double operator *(const Point &a, const Point &b) { return a.x*b.x + a.y*b.y; }
bool operator <(const Point &a, const Point &b) { 
    if (abs(a.x - b.x) < EPS) {
        return a.y < b.y;
    }
    return a.x < b.x;
}
bool operator ==(const Point &a, const Point &b) {
    return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS;
}

double cross(Point a, Point b) {
    return a.x*b.y - a.y*b.x;
}

double cross(Point a, Point b, Point c) {
    return cross(a - b, c - b);
}

struct Circle {
    double r;
    Point c;
    Circle(){}
    Circle(double r, Point c):r(r), c(c){}
};

vector <Point> getPoints(vector <Circle> &circles) {
    vector <Point> ans;
    REP(i, SZ(circles)) {
        REPR(j, i+1, SZ(circles)) {
            double R = circles[j].r;
            double r = circles[i].r;
            Point DC = circles[j].c - circles[i].c;
            if (DC.mod() + r <= R + EPS) {
                continue;
            }

            double dr = R - r;
            double dt = sqrt(DC.mod2() - dr*dr);
            double dtr2 = dt*dt + dr*dr;

            Point u1, u2;
            u1.y = (DC.y*dt + DC.x*dr)/dtr2;
            u1.x = (DC.x - dr*u1.y)/dt;

            // cout << u1.x << " " << u1.y << endl;
            u1 = u1.ort();
            Point p[4];
            p[0] = circles[i].c + u1*circles[i].r;
            p[1] = circles[j].c + u1*circles[j].r;

            u2.y = (DC.y*dt - DC.x*dr)/dtr2;
            u2.x = (DC.x + dr*u2.y)/dt;
            u2 = u2.ort();
            p[2] = circles[i].c - u2*circles[i].r;
            p[3] = circles[j].c - u2*circles[j].r;

            p[0].tag = p[2].tag = i;
            p[1].tag = p[3].tag = j;
            REP(k, 4) {
                ans.push_back(p[k]);
            }
        }
    }
    sort(all(ans));
    int l = unique(all(ans)) - ans.begin();
    if (l < SZ(ans)) {
        ans = vector<Point>(ans.begin(), ans.begin() + l);
    }

    return ans;
}

vector <Point> convexHull(vector <Point> &points) {
    Point ref = points[0];
    vector<pair <double, Point> > order;
    order.push_back({0, ref});

    REPR(i, 1, SZ(points)) {
        Point a = points[i];
        order.push_back({(a - ref).ang(), a});
    }

    sort(order.begin() + 1, order.end());

    vector <Point> ans;
    for (auto it: order) {
        Point p = it.second;
        while (ans.size() > 1 && cross(p, ans[SZ(ans)-1], ans[SZ(ans) - 2]) < EPS) {
            ans.pop_back();
        }
        ans.push_back(p);
    }
    return ans;
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector <Circle> circles;
        int x, y, r;
        REP(i, n) {
            cin >> x >> y >> r;
            circles.push_back(Circle(r, Point(x, y)));
        }

        sort(all(circles), [](Circle a, Circle b) { return a.r < b.r; });
        vector <Point> points = getPoints(circles);

        double ans = 0;
        if (SZ(points) == 0) {
            double r = circles[SZ(circles) - 1].r;
            ans += 2*PI*r;
        } else {
            assert(SZ(points) >= 3);
            points = convexHull(points);
            REP(i, SZ(points)) {
                Point a = points[i], b = points[(i+1)%SZ(points)];
                if (a.tag != b.tag) {
                    ans += (a - b).mod();
                } else {
                    double theta = (b - circles[b.tag].c).ang() - (a - circles[a.tag].c).ang();
                    if (theta < 0) {
                        theta += 2*PI;
                    }
                    ans += circles[a.tag].r*theta;
                }
            }
        }

        printf("%.10f\n", ans);        
    }

    cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
