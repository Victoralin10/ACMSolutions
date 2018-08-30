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
    int t, k, p;
    set <Pair> st;
    while (cin >> t && t > 0) {
        if (t == 1) {
            cin >> k >> p;
            st.insert({p, k});
        } else if (SZ(st) == 0) puts("0");
        else {
            if (t == 3) {
                cout << st.begin()->second << endl;
                st.erase(st.begin());
            } else {
                cout << st.rbegin()->second << endl;
                st.erase(*st.rbegin());
            }
        }
    }
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
