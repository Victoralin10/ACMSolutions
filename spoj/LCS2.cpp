#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

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

#define N 1000011
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

/************************************/

struct St {
    int len, link;
} st[2*N];
int nxt[2*N][36];

int sz=0, last;

void sa_init() {
//CLR(nxt, -1);
    sz=last=0;
    st[0].len=0;
    st[0].link=-1;
    sz++;
}

void sa_extend(char c) {
    if (c >= 'a') c -= 'a';
    else c=c+26-'A';

    int cur=sz++, p;
    st[cur].len=st[last].len+1;
    
    for(p=last; p!=-1 && !nxt[p][c]; p=st[p].link)
        nxt[p][c]=cur;

    if (p==-1) st[cur].link=0;
    else {
        int q=nxt[p][c];
        if (st[p].len+1==st[q].len) st[cur].link=q;
        else {
            int clone=sz++;
            st[clone].len=st[p].len+1;
            st[clone].link=st[q].link;
            memcpy(nxt[clone], nxt[q], sizeof(nxt[0]));

            for(;p!=-1 && nxt[p][c]==q; p=st[p].link)
                nxt[p][c]=clone;

            st[q].link=st[cur].link=clone;
        }
    }
    last=cur;
}

char line[N];
int dp[2*N];
vector <int> G[2*N];
int L[2*N];
Pair ord[2*N];

int main() {
    int n=0, l;
    sa_init();
    while (scanf("%s", line) != EOF) {
        l=strlen(line);
        REP(i,l) sa_extend(line[i]);
        sa_extend('A'+n);
        dp[last]=(1<<n);
        L[last]=l;
        n++;
    }

    REP(i, sz) {
        REP(j, 36)
            if (nxt[i][j])
            G[nxt[i][j]].push_back(i);
        ord[i] = {-st[i].len, -i};
    }
    sort(ord, ord + sz);

    int ans=0, msk=(1<<n)-1;
    REP(i, sz) {
        Pair &x=ord[i];
        x.second=-x.second;
        if (L[x.second]==0) continue;
        for (int &p: G[x.second]) {
            if (L[p]>0) L[p]=min(L[p], L[x.second]-1);
            else L[p]=L[x.second]-1;
            dp[p] |= dp[x.second];
        }
        if (dp[x.second]==msk) {
            ans=st[x.second].len;
            break;
        }
    }
    printf("%d\n", ans);

    return 0 ;
}
