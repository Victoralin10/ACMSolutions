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
//#define EPS 1e-8

using namespace std;

struct Frac {
    int n, d;
    Frac(){d = 1; }
    Frac(int _n){n = _n; d = 1; }
    Frac(int n, int d):n(n), d(d){}
    void reducir() {
        // cout << n <<  " " << d << endl;
        int g = __gcd(abs(n), abs(d));
        if (g == 1) return;
        if (n == 0) {
            d = 1;
            return;
        }
        n /= g;
        d /= g;
        if (d < 0) {
            d = -d;
            n = -n;
        }
    }
};

Frac operator-(const Frac &a) {return Frac(-a.n, a.d); }
Frac operator- (const Frac &a, const Frac &b) {
    Frac ans(a.n*b.d - a.d*b.n, a.d*b.d);
    ans.reducir();
    return ans;
}
Frac operator+ (const Frac &a, const Frac &b) {
    Frac ans(a.n*b.d + a.d*b.n, a.d*b.d);
    ans.reducir();
    return ans;
}
Frac operator* (const Frac &a, const Frac &b) {
    Frac ans(a.n*b.n, a.d*b.d);
    ans.reducir();
    return ans;
}
Frac operator/ (const Frac &a, const Frac &b) {
    Frac ans(a.n*b.d, a.n*b.n);
    ans.reducir();
    return ans;
}
Frac operator* (int k, const Frac &b) {
    Frac ans(b.n*k, b.d);
    ans.reducir();
    return ans;
}
bool operator ==(Frac a, Frac b) {
    a.reducir(); b.reducir();
    return a.n==b.n && a.d==b.d;
}
bool operator <(const Frac &a, const Frac &b) {
    return a.n*b.d < a.d*b.n;
}
bool operator <=(const Frac &a, const Frac &b) {
    return a.n*b.d <= a.d*b.n;
}

struct Point {
    Frac x, y;
    Point(){};
    Point(Frac x, Frac y):x(x),y(y) {}
    Point ort() { return Point(-y, x); }
};

int C[MAXN][MAXN];
Point P[MAXN];
int V[MAXN];

Point operator- (const Point &a, const Point &b) { return Point(a.x-b.x, a.y-b.y); }
Point operator+ (const Point &a, const Point &b) { return Point(a.x+b.x, a.y+b.y); }
Point operator* (int r, const Point &b) { return Point(r*b.x, r*b.y); }
Point operator* (const Frac r, const Point &b) { return Point(r*b.x, r*b.y); }
Frac operator* (const Point &a, const Point &b) { return a.x*b.x + a.y*b.y; }
bool operator== (const Point &a, const Point &b) { return a.x==b.x && a.y==b.y; }
bool operator< (const Point &a, const Point &b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

Point intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
    Frac r = (c - a)*((d - c).ort());
    r = r/((b - a)*((d -c).ort()));
    return a + r*(b - a);
}

bool inSegment(const Point &a, const Point &b, const Point &x) {
    return (x - a)*((x - b).ort()) == Frac(0) && (x - a)*(x - b) <= Frac(0);
}

bool isCity(const Point &a, int n) {
    for (int i = 0; i < n; i++) {
        if (a == P[i]) return true;
    }
    return false;
}

int main(int nargs, char **args) {
    for (int i = 0; i < MAXN; i++) {
        V[i] = i;
    }
    int n, c, casos = 1;
    while (cin >> n >> c) {
        if (n + c == 0) break;
        for (int i = 0, x, y; i < n; i++) {
            cin >> x >> y;
            P[i] = Point(Frac(x), Frac(y));
        }

        for (int i = 0; i < n; i++) {
            for (int  j = 0; j < n; j++) {
                cin >> C[i][j];
            }
        }
        
        int ans = (1<<30), pa;
        do {
            pa = 0;
            for (int i = 0; i < n; i++) {
                pa += C[V[i]][V[(i+1)%n]];
            }

            vector < Point > ints;
            for (int i = 0; i < n; i++) {
                for (int j = i + 2; j < n; j++) {
                    if (i == 0 && j+1 == n) continue;
                    Point x = intersect(P[V[i]], P[V[(i+1)%n]], P[V[j]], P[V[(j+1)%n]]);
                    if (inSegment(P[V[i]], P[V[(i+1)%n]], x) && !isCity(x, n)) {
                        ints.pb(x);
                    }
                }
            }
            sort(ints.begin(), ints.end());
            for (int i = 0, j, k; i < ints.size(); ) {
                j = i;
                while (j < ints.size() && ints[j] == ints[i]) j++;
                k = (j - i)*2;
                pa += c*(k*(k-1))/2;
                i = j;
            }
            ans = min(pa, ans);
        } while (next_permutation(V, V + n));
        cout << (casos++) << ". " << ans << endl;
    }
    return 0;
}
