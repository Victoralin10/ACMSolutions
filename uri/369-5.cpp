#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

clock_t _inicio = clock();

typedef long long Long;
typedef vector <int> vInt;
typedef pair <int, int> Pair;

map <string, int> idMap;
int nid = 0;

int getId(const string &name) {
    if (idMap.find(name) == idMap.end()) {
        idMap[name] = nid++;
    }
    return idMap[name];
}

int H[500];
int F(int x) { return x==H[x]?x:H[x]=F(H[x]); }
void U(int x, int y) { H[F(x)]=F(y); }

int main(int nargs, char **args) {
    int n, m;
    cin >> n >> m;
    string n1, n2, rel;
    REP(i, n) H[i] = i;
    REP(i, m) {
        cin >> n1 >> rel >> n2;
        U(getId(n1), getId(n2));
    }
    int cnt = 0;
    REP(i, n) cnt += (i==H[i]);
    cout << cnt << endl;

    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
