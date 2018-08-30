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
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    ll b, q, m, l;
    cin >> b >> q >> l >> m;

    set <int> st;
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        st.insert(x);
    }

    if (b == 0) {
        if (st.find(0) == st.end()) puts("inf");
        else puts("0");
    } else if (q == 0) {
        if (abs(b) > l) puts("0");
        else if (st.find(b) != st.end() && st.find(0) != st.end()) puts("0");
        else if (st.find(0) != st.end()) puts("1");
        else puts("inf");
    } else if (q == -1) {
        if (abs(b) > l) puts("0");
        else if (st.find(b) != st.end() && st.find(-b) != st.end()) puts("0");
        else puts("inf");
    } else if (q == 1) {
        if (abs(b) > l) puts("0");
        else if (st.find(b) != st.end()) puts("0");
        else puts("inf");
    } else {
        int ans = 0;
        while (abs(b) <= l) {
            ans += (st.find(b) == st.end());
            b *= q;
        }

        cout << ans << endl;
    }
    return 0;
}
