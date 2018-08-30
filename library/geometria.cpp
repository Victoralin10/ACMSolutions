#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef pair <int, int> Pair;

namespace geo_int {

struct Pto {
    Long x=0, y=0;
    Pto(){}
    Pto(Long x, Long y): x(x), y(y){}
    Pto ort() { return Pto(-y, x); }
    Long mod2() { return x*x + y*y; }
    Pto operator +(const Pto &p) const { return Pto(x + p.x, y + p.y); }
    Pto operator -(const Pto &p) const { return Pto(x - p.x, y - p.y); }
    Pto operator *(Long k) const { return Pto(x*k, y*k); }
    Long operator *(const Pto &p) const { return x*p.x + y*p.y; }
    Long operator ^(const Pto &p) const { return x*p.y - y*p.x; }
    bool operator <(const Pto &p) const { return x==p.x?y<p.y:x<p.x; }
    bool operator ==(const Pto &p) const { return x==p.x && y==p.y; }
    bool operator !=(const Pto &p) const { return x!=p.x || y!=p.y; }
};

vector <Pto> chull(vector <Pto> &pts) {
    if (pts.size() < 3) {
        return pts;
    }

    Pto _ref = *min_element(all(pts), [](const Pto &a, const Pto &b) { 
        return a.y==b.y?a.x<b.x:a.y<b.y;
    });

    sort(all(pts), [_ref](const Pto &a, const Pto &b) {
        Pto ra = a - _ref, rb = b - _ref;
        Long ar = ra^rb;
        return ar==0?ra.mod2()<rb.mod2():ar>0;
    });

    vector <Pto> ans;
    int i = 0, s;
    while (i < SZ(pts)) {
        s = SZ(ans);
        if (s > 1 && ((pts[i] - ans[s-1])^(ans[s-2] - ans[s-1])) <= 0) ans.pop_back(); // < 0
        else ans.push_back(pts[i++]);
    }

    return ans;
}

bool isConvex(vector <Pto> &pts) {
    int cnt1 = 0, cnt2 = 0, n = SZ(pts);
    REP(i, n) {
        Pto &a = pts[i], &b = pts[(i+1)%n], &c = pts[(i+2)%n];
        if (((c-b)^(a - b)) < 0) cnt1++;
        else cnt2++;
    }
    return !cnt1 || !cnt2;
}

Long area(vector <Pto> &pts) {
    Long ans = 0;
    int n = SZ(pts);
    REPR(i, 1, n) {
        ans += pts[i]^pts[i-1];
    }
    return abs(ans);
}

}

namespace geo_double {

typedef long double Double;
const Double EPS = 1e-9;

struct Pto {
    Double x=0, y=0;
    Pto(){}
    Pto(Double x, Double y): x(x), y(y){}

    Double mod2() { return x*x + y*y; }
    Double mod() { return sqrt(mod2()); }
    Pto ort() { return Pto(-y, x); }
    Pto unit() { Double k = mod(); return Pto(x/k, y/k); }
    Pto operator +(const Pto &p) const { return Pto(x + p.x, y + p.y); }
    Pto operator -(const Pto &p) const { return Pto(x - p.x, y - p.y); }
    Pto operator *(Double k) const { return Pto(x*k, y*k); }
    Pto operator /(Double k) const { return Pto(x/k, y/k); }
    Double operator *(const Pto &p) const { return x*p.x + y*p.y; }
    Double operator ^(const Pto &p) const { return x*p.y - y*p.x; }
    bool operator <(const Pto &p) const { return abs(x-p.x)<EPS?y<p.y:x<p.x; }
    bool operator ==(const Pto &p) const { return abs(x-p.x)<EPS && abs(y-p.y)<EPS; }
    bool operator !=(const Pto &p) const { return abs(x-p.x)>EPS || abs(y-p.y)>EPS; }
};

Pto _ref;
bool radialOrder(const Pto &a, const Pto &b) {
    Pto ra = a - _ref, rb = b - _ref;
    Long ar = ra^rb;
    return abs(ar)<EPS?ra.mod2()<rb.mod2():ar>0;
}

bool yxOrder(const Pto &a, const Pto &b) { return abs(a.y-b.y)<EPS?a.x<b.x:a.y<b.y; }

vector <Pto> chull(vector <Pto> &pts) {
    if (pts.size() < 3) {
        return pts;
    }
    _ref = *min_element(all(pts), radialOrder);
    sort(all(pts), yxOrder);

    vector <Pto> ans;
    int i = 0, s;
    while (i < SZ(pts)) {
        s = SZ(ans);
        if (s > 1 && ((pts[i] - ans[s-1])^(ans[s-2] - ans[s-1])) <= EPS) ans.pop_back(); // < -EPS
        else ans.push_back(pts[i++]);
    }
    return ans;
}

Double area(vector <Pto> &pts) {
    Double ans = 0;
    int n = SZ(pts);
    REPR(i,1,n) {
        ans += pts[i]^pts[i-1];
    }
    return abs(ans);
}

bool isConvex(vector <Pto> &pts) {
    int cnt1 = 0, cnt2 = 0, n = SZ(pts);
    REP(i, n) {
        Pto &a = pts[i], &b = pts[(i+1)%n], &c = pts[(i+2)%n];
        if (((c-b)^(a - b)) < EPS) cnt1++;
        else cnt2++;
    }
    return !cnt1 || !cnt2;
}

struct Segm {
    Pto s, e;
    Segm(){}
    Segm(Pto s, Pto e):s(s), e(e){}
    Double len() { return (e-s).mod(); }
    Pto dir() const { return e-s; }
};

bool areParallel(const Segm &a, const Segm &b) {
    return abs(a.dir()^b.dir()) < EPS;
}

Pto lineIntersect(const Segm &a, const Segm &b) {
    assert(!areParallel(a, b));
    Pto bort = b.dir().ort();
    double r = ((b.s - a.s)*bort)/(b.dir()*bort);
    return a.s + a.dir()*r;
}

bool onSegment(const Segm &a, const Pto &b) {
    if (abs((a.s - b)^(a.e - b)) > EPS) return false;
    return (a.s - b)*(a.e - b) < EPS;
}

bool segmIntersect(const Segm &a, const Segm &b) {
    if (areParallel(a, b)) return false;
    Pto I = lineIntersect(a, b);
    return onSegment(a, I) && onSegment(b, I);
}

}