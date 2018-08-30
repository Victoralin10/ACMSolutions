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
    int q;
    Long n, x, y, ans;
    cin >> n >> q;
    while (q--) {
        cin >> x >> y;
        if ((x+y)%2 == 1) ans = (n*n + 1)/2;
        else ans = 0;

        if (n%2 == 0) {
            ans += (x-1)*(n/2) + (y+1)/2;
        } else {
            ans += ((x-1)/2)*n;
            ans += (y+1)/2;
            if (x%2 == 0) {
                ans += n/2 + ((x+y)%2==0);
            }
        }
        cout << ans << endl;
    }
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
