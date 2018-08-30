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


bool query(int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return false;

    cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    cout.flush();
    string ans;
    cin >> ans;
    return ans=="YES";
}


char A[501], B[501];

int main(int nargs, char **args) {
    int n, r = 1, c = 1, r2, c2;
    cin >> n;

    REP(i, n - 1) {
        if (query(r + 1 , c, n, n)) {
            A[i] = 'D';
            r++;
        } else {
            A[i] = 'R';
            c++;
        }
    }

    r2 = n, c2 = n;
    REP(i, n - 1) {
        if (query(1, 1, r2, c2 -1)) {
            B[i] = 'R';
            c2--;
        } else {
            B[i] = 'D';
            r2--;
        }
    }

    A[n-1] = B[-1] = 0;
    reverse(B, B + n - 1);

    cout << "! " << A << B << endl;
    cout.flush();

    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
