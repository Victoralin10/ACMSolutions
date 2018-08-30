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
    string s, v = "aeiou";
    int ans = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        ans += (v.find(s[i]) != string::npos || (s[i] >= '0' && s[i] <= '9' && (s[i] - '0')%2 == 1));
    }
    cout << ans << endl;
    return 0;
}
