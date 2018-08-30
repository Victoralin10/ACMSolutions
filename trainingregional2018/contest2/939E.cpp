#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define CLR(t, value) memset(t, value, sizeof(t))
#define ALL(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;
#define sc(x) scanf("%d", &x)

using namespace std;

typedef long long Long;
typedef vector<int> vInt;
typedef pair<int,int> Pair;

const int N = 1e6 + 2;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

/************************************/

typedef long double Double;

struct Sg {
    Double x, y, a, b;
    Sg(){}
    Sg(Double x, Double y, Double a, Double b):x(x), y(y), a(a), b(b){}
} sg[N];

pair <Double, Double> inter(const Sg &a, const Sg &b) {
    Double x=(b.b-a.b)/(a.a-b.a);
    Double y=a.a*x+a.b;
    return {x, y};
}

int csg=0, lst=0;
Sg last;

void add(Sg a) {
    if (lst) {
        bool ok=0;
        pair<Double,Double> in;
        do {
            if (csg>0) {
                in = inter(last, sg[csg-1]);
                if (in.first<sg[csg-1].x) csg--;
                else ok=1;
            }
        } while(!ok && csg>0);
        if (csg) sg[csg++]=Sg(in.first,in.second,last.a,last.b);
        else sg[csg++]=last;
    }
    lst=1;
    last=a;
}

Double query(double x) {
    if (!csg) return 0;
    int lo=0, hi=csg, mid;
    while (hi-lo>1) {
        mid=(hi+lo)>>1;
        if (sg[mid].x>x) hi=mid;
        else lo=mid;
    }
    return sg[lo].a*x+sg[lo].b;
}

int main() {
    int q, t, x;
    cin >> q;
    sg[0] = Sg(0,-1e10,0,-1e10);

    Double acum=0, cnt=1;
    while (q--) {
        cin>>t;
        if (t==1) {
            cin>>x;
            cnt++;
            acum += x;
            Sg nsg(0,-acum/cnt,(cnt - 1)/cnt,-acum/cnt);
            add(nsg);
        } else {
            printf("%.8f\n", (double)query(x));
        }
    }

    return 0 ;
}
