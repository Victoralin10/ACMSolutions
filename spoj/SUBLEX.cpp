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
    map<char,int> next;
}st[2*N];
int sz=0, last;

void sa_init() {
    REP(i,sz)st[i].next.clear();

    sz=last=0;
    st[0].len=0;
    st[0].link=-1;
    sz++;
}

void sa_extend(char c) {
    int cur=sz++, p;
    st[cur].len=st[last].len+1;
    
    for(p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c]=cur;

    if (p==-1) st[cur].link=0;
    else {
        int q=st[p].next[c];
        if (st[q].len==st[p].len+1) st[cur].link=q;
        else {
            int clone=sz++;
            st[clone].len=st[p].len+1;
            st[clone].link=st[q].link;
            st[clone].next=st[q].next;

            for(; p!=-1&&st[p].next[c]==q; p=st[p].link)
                st[p].next[c]=clone;

            st[cur].link=st[q].link=clone;
        }
    }
    last=cur;
}

int cnt[2*N];

int main() {
    string line;
    cin>>line;

    sa_init();
    REP(i,SZ(line)) sa_extend(line[i]);
    vector<Pair> ord;
    REP(i, sz) ord.push_back({st[i].len, i});
    sort(ALL(ord));
    reverse(ALL(ord));

    REP(i,sz) {
        int q=ord[i].second;
        cnt[q]=1;
        for (auto it: st[q].next) {
            cnt[q] += cnt[it.second];
        }
    }

    int nq, k, p;
    cin>>nq;
    while(nq--) {
        cin>>k;
        string ans="";
        p=0;
        while (k>0) {
            for (auto it: st[p].next) {
                if (k>cnt[it.second])  k -= cnt[it.second];
                else {
                    k--;
                    ans.push_back(it.first);
                    p=it.second;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }


    return 0 ;
}
