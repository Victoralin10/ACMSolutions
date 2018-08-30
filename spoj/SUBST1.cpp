#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define CLR(t, value) memset(t, value, sizeof(t))
#define ALL(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;
#define sc(x) scanf("%d", &x)
#define FORIT(it, mp) for(typeof mp.begin() it=mp.begin(); it != mp.end(); it++)

using namespace std;

typedef long long Long;
typedef vector<int> vInt;
typedef pair<int,int> Pair;

const int N = 5e4 + 2;
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
    st[0].len = 0;
    st[0].link = -1;
    sz++;
}

void sa_extend(char c) {
    int cur = sz++, p;
    st[cur].len = st[last].len+1;

    for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c] = cur;

    if (p==-1) st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if (st[p].len+1==st[q].len) st[cur].link=q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len+1;
            st[clone].link = st[q].link;
            st[clone].next = st[q].next;

            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;

            st[cur].link = st[q].link = clone;
        }
    }
    last = cur;
}

Long memo[2*N];

Long dp(int state) {
    Long &ans = memo[state];
    if (ans == -1) {
        ans = 1;
        FORIT(it, st[state].next) ans += dp(it->second);
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        sa_init();
        string line;
        cin >> line;
        REP(i, SZ(line)) sa_extend(line[i]);
        CLR(memo, -1);
        cout << (dp(0) - 1) << endl;
    }

    return 0 ;
}
