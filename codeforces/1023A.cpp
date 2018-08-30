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


int main(int nargs, char **args) {
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;

    int pos = a.find('*');
    if (pos >= 0 && n <= m + 1) {
        b = b.substr(0, pos) + "*" + b.substr(m - (n - pos - 1));
    }
    //TEST(b);
    puts(a==b?"YES":"NO");

    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
