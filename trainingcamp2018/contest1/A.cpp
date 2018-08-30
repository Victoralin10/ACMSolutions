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
    
    int m, s;
    cin >> m >> s;
    if (9*m < s || (m > 1 && s == 0)) {
        puts("-1 -1");
    } else {
        char a1[m+1], a2[m+1];
        a1[m] = 0, a2[m] = 0;
        for (int i = 0, d, r = s; i < m; i++) {
            d = min(9, r);
            a2[i] = d + '0';
            r -= d;
        }
        for (int i = m-1, d, r = s; i >= 0; i--) {
            d = min(9, r);
            if (d == r && i > 0) {
                d--;
            }
            a1[i] = d + '0';
            r -= d;
        }
        cout << a1 << " " << a2 << endl;
    }

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
