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
    int a, b;
    string s1, s2;
    cin >> a >> b >> s1 >> s2;

    int ans = (1<<30), ci;
    for (int i = b-a; i >= 0; i--) {
        int ne = 0;
        for (int j = 0; j < a; j++) {
            ne += s1[j]==s2[i+j];
        }
        if (a - ne < ans) {
            ans = a - ne;
            ci = i;
        }
    }

    cout << ans << endl;
    for (int i = 0, j = ci; i < a; i++, j++) {
        if (s1[i] != s2[j]) {
            cout << (i+1) << " ";
        }
    }
    
    return 0;
}
