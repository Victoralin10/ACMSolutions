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

#define MOD 1000000007
#define MAXN 200005

using namespace std;


map <int, int> DP[MAXN];
vector <int> G[MAXN];
int n;
char label[MAXN];

void dfs1(int nd, int parent) {
    for (int i = 0, h; i < G[nd].size(); i++) {
        h = G[nd][i];
        if (h == parent) continue;
        dfs1(h, nd);
    }

    DP[nd][1<<(label[nd-1] - 'a')] = 1;
    
}

int main(int nargs, char **args) {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    scanf("%s", label);
    

    return 0;
}
