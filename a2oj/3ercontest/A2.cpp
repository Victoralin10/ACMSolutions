#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())

typedef long long Long;
typedef vector<int> vInt;
typedef vector<vInt> vvInt;
typedef vector<string> vStr;
typedef pair<int, int> Pair;
typedef vector<pair<int, int> > vPair;

int a[ 100 ] ;

int main(int nargs, char **args) {
    int n ;
    cin >> n ;
    for( int i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
    }
    if( a[ n ] == 15 ) {
        cout << "DOWN" ;
        return 0 ;
    }
    if( a[ n ] == 0 ) {
        cout << "UP" ;
        return 0 ;
    }
    if( n == 1 ) {
        cout << "-1" ;
        return 0 ;
    }
    if( a[ n - 1 ] < a[ n ] ) {
        cout << "UP" ;
    } else {
        cout << "DOWN" ;
    }

    return 0;
}
