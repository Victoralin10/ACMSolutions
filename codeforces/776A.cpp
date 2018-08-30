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
    string a, b, c, d;
    int n;
    cin >> a >> b >> n;

    cout << a << " " << b << endl;
    while (n--) {
        cin >> c >> d;
        if (c == a) {
            a = d;
        } else {
            b = d;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
