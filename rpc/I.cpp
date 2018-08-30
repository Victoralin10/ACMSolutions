#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef vector <vInt> vvInt;
typedef vector <string> vStr;
typedef pair <int, int> Pair;
typedef vector <pair <int, int> > vPair;


int main(int nargs, char **args) {
    clock_t _inicio = clock();

    int n, h;
    cin >> n;
    int C[n];
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    cin >> h;
    int ans = -1;
    for (int i = 0, mn = (1<<30); i < n; i++) {
        if (h%C[i] < mn) {
            mn = h%C[i];
            ans = C[i];
        }
    }
    cout << ans << endl;

    // fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
