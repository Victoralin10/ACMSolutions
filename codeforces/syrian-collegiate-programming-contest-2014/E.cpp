#include <bits/stdc++.h>

#define MAXN 55

using namespace std;

int memo[MAXN];
int n, k;

int grundy(int n) {
    if (n < k) return 0;
    if (n == k) return 1;
    if (memo[n] != -1) return memo[n];

    int &ans = memo[n];
    set <int> st;
    for (int i = 0; i < n - k; i++) {
        st.insert(grundy(i)^grundy(n - i - k));
    }
    ans = 0;
    while (st.find(ans) != st.end()) ans++;
    return ans;
}

int main(int nargs, char **args) {
    int t;
    cin >> t;
    for (int caso = 1; caso <= t; caso++) {
        cin >> n >> k;
        memset(memo, -1, sizeof memo);
        cout << "Case " << caso << ": " << (grundy(n)?"Winning":"Losing") << endl;
    }    
    return 0;
}
