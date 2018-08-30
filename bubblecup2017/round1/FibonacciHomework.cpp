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
    int a = 0, b = 1, ant = -1;
    // cout << "0\n1\n";
    set <int> st;
    for (int i = 2; i <= 10000000; i++) {
        a = (a + b) % MOD;
        swap(a, b);
        if (st.find(b) != st.end()) {
            //cout << b << endl;
            if (i - ant == 1) cout << i << " ok" << endl;
            ant = i;
        }
        // cout << b << endl;
        st.insert(b);
    }
    return 0;
}
