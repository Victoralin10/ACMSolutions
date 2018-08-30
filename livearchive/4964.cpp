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
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a == b && b == c && a == 0) break;

        if (b - a == c - b) {
            cout << "AP " << 2*c - b << endl;
        } else {
            cout << "GP " << c*(c/b) << endl;
        }
    }
    return 0;
}
