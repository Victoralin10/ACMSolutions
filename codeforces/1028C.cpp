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

const int N = 2e5 + 2;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

/************************************/

typedef pair <Pair, Pair> rec;
vector <rec> recs;
rec Il[N], Ir[N];
bool vl[N], vr[N];

bool intersect(rec a, rec b, rec &c) {
    if (a.first.first > b.first.first) swap(a, b);
    if (a.second.first < b.first.first) return false;
    if (a.second.second < b.first.second || a.first.second > b.second.second) return false;

    c.first = {b.first.first, max(a.first.second, b.first.second)};
    c.second = {min(a.second.first, b.second.first), min(a.second.second, b.second.second)};

    return true;
}

int main() {
    int n, x[4];
    cin >> n;

    REP(i, n) {
        REP(j, 4) sc(x[j]);
        recs.push_back({{x[0], x[1]}, {x[2], x[3]}});
    }

    Il[0] = {{-MOD, -MOD}, {MOD, MOD}};
    Ir[n] = {{-MOD, -MOD}, {MOD, MOD}};
    REP(i, n) {
        if (!intersect(recs[i], Il[i], Il[i+1])) {
            break;
        }
        vl[i+1] = 1;
    }
    for (int i = n-1; i >= 0; i--) {
        if (!intersect(recs[i], Ir[i+1], Ir[i])) {
            break;
        }
        vr[i] = 1;
    }
    vl[0] = vr[n] = 1;
    if (vr[0]) {
        cout << Ir[0].first.first << " " << Ir[0].first.second << endl;
    } else {
        rec aux;
        REP(i, n) {
            if (!vl[i] || !vr[i+1]) continue;
            if (intersect(Il[i], Ir[i+1], aux)) {
                break;
            }
        }
        cout << aux.first.first << " " << aux.first.second << endl;
    }

    return 0 ;
}
