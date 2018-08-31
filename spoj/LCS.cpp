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

const int N = 3e5 + 2;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

/************************************/

struct St {
    int len, link;
    map<char, int> next;
}st[2*N];
int sz=0,last;

void sa_init(){
    REP(i,sz)st[i].next.clear();
    sz=last=0;
    st[0].len=0;
    st[0].link=-1;
    sz++;
}

void sa_extend(char c) {
    int cur=sz++,p;
    st[cur].len=st[last].len+1;

    for(p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c]=cur;

    if(p==-1)st[cur].link=0;
    else {
        int q=st[p].next[c];
        if(st[p].len+1==st[q].len) st[cur].link=q;
        else {
            int clone=sz++;
            st[clone].len=st[p].len+1;
            st[clone].link=st[q].link;
            st[clone].next=st[q].next;

            for(;p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c]=clone;

            st[q].link=st[cur].link=clone;
        }
    }
    last=cur;
}

char a[N], b[N];

int main() {
    scanf("%s%s", a, b);
    int l1=strlen(a), l2=strlen(b);

    sa_init();
    REP(i,l1) sa_extend(a[i]);

    int ans=0,p=0, cl=0;
    REP(i,l2) {
        while (p!=-1 && st[p].next.count(b[i])==0) {
            cl=min(cl, (p>0?st[st[p].link].len:0));
            p=st[p].link;
        }
        if (p==-1) p=0;
        else {
            p=st[p].next[b[i]];
            cl++;
            ans=max(ans, cl);
        }
    }
    cout<<ans<<endl;

    return 0 ;
}
