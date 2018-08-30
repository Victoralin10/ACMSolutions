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

bool used[30];

int main(int nargs, char **args) {
    string s;
    cin >> s;

    bool ok = 1;
    int cnt = 0;
    
    for (int i = 0; i < s.size() && ok; i++) {
        if (!used[s[i] - 'a']) {
            if (cnt == s[i] - 'a') used[cnt++] = 1;
            else ok = 0;
        }
    }

    puts(ok?"YES":"NO");

    return 0;
}
