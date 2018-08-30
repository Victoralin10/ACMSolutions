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
    int n, r;
    cin >> n;
    r = (int)sqrt(n + 0.5);
    while (n > 0) {
        int a = max(n - r, 0), b = n;
        REPR(i, a, b) {
            cout << i+1 << " ";
            n--;
        }
    }
    cout << endl;

    cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
