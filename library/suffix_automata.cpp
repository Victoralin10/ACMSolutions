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

const int N = 1e5 + 2;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

/************************************/

struct St {
    int len, link;
    map <char, int> next;
} st[2*N];

int sz = 0, last;

void sa_init() {
    REP(i, sz) st[i].next.clear();
    sz = last = 0;
    st[last].len = 0;
    st[last].link = -1;
    sz++;
}

void sa_extend(char c) {
    int cur = sz++, p;
    st[last].next[c] = cur;
    st[last].len = st[last].len + 1;
    for (p = st[last].link; p != -1 && !st[p].next.count(c); p = st[p].link)
        st[p].next[c] = cur;
    
    if (p == -1) st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].link = st[q].link;
            st[clone].next = st[q].next;

            for (; p != -1 && st[p].next[c] == q; p = st[p].link)
                st[p].next[c] = clone;

            st[q].link = st[cur].link = clone;
        }
    }

    last = cur;
}

int main() {

    return 0 ;
}
