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
#define MAXN 1000006

using namespace std;

int n, T[MAXN], tt = 0, S[MAXN];
vector <int> G[MAXN];
int tob;

int A[10], ca = 0;

bool dfs(int node, int parent) {
    S[node] = T[node];
    int cnt = 0;
    for (int i = 0; i < G[node].size(); i++) {
        int nn = G[node][i];
        if (nn == parent) continue;
        cnt += dfs(nn, node);
        S[node] += S[nn];
    }
    if (ca == 2) return 0;
    if (node != G[0][0] && cnt == 0 && S[node] == tob) {
        A[ca++] = node;
        cnt++;
    } else if (node != G[0][0] && S[node] == 2*tob && cnt > 0) {
        A[ca++] = node;
        cnt++;
    }
    return cnt > 0;
}

int main(int nargs, char **args) {
    scanf("%d", &n);
    for (int u = 1, v, t; u <= n; u++) {
        scanf("%d%d", &v, &t);
        if (v > 0) {
            G[u].pb(v);
        }
        G[v].pb(u);
        T[u] = t;
        tt += t;
    }

    if (tt%3 != 0) {
        puts("-1");
    } else {
        tob = tt/3;
        dfs(G[0][0], -1);
        if (ca != 2) {
            puts("-1");
        } else {
            cout << A[0] << " " << A[1] << endl;
        }
    }

    return 0;
}
