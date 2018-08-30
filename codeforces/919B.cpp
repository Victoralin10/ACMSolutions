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


bool isPerfect(int n) {
    int s = 0;
    while (n) {
        s += n%10;
        n /= 10;
    }
    return s == 10;
}

int main(int nargs, char **args) {
    int k, c = 18;
    cin >> k;
    while (k) {
        k -= isPerfect(++c);
    }
    cout << c << endl;
    return 0;
}
