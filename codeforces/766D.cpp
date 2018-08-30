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
#define MAXN 100005

using namespace std;

map <string, int> mp;
int H[MAXN];
int ng = 0;

int F(int x) {return x==H[x]?x:H[x]=F(H[x]); }
void U(int x, int y) { H[F(x)] = F(y); }

int main(int nargs, char **args) {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        mp[a] = i;
        H[i] = i;
    }

    ng = n + (n&1);
    memset(G, -1, sizeof G);
    for (int i = 0, op; i < m; i++) {
        string a, b;
        cin >> op >> a >> b;
        int id1 = mp[a], id2 = mp[b];
        if (G[id1] == -1 && G[id2] == -1) {
            G[id1] = U(id1, ng);
            G[id2] = U(id2, ng + (op == 2));
            ng += 2;
        } else if (G[id1] == -1) {
            G[id2] = U(id2, G[id1]^(op==2));
        } else if (G[id1] == -1) {
            G[id1] = U(id1, G[id2]^(op==2));
        } else {
            
        }
    }

    return 0;
}
