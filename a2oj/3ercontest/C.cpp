#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef vector <vInt> vvInt;
typedef vector <string> vStr;
typedef pair <int, int> Pair;
typedef vector <pair <int, int> > vPair;

string s ;

void printSolveAddOne() {
    string num ;
    for( int i = 0 ; s[ i ] != '.' ; i ++ ) {
        num += s[ i ] ;
    }
    int it = num.size() - 1 ;
    for( ; it >= 0 ; it -- ) {
        if( num[ it ] < '9' ) {
            num[ it ] ++ ;
            break ;
        } else {
            num[ it ] = '0' ;
            if( it == 0 ) {
                num = "1" + num ;
            }
        }
    }
    cout << num ;
}

int main(int nargs, char **args) {
    int n , k ;
    cin >> n >> k ;
    cin >> s ;
    bool inDecimal = false ;
    int it = 0 ;
    for( ; it < n ; ) {
        if( s[ it ] == '.' ) {
            inDecimal = true ;
            it ++ ;
            continue ;
        }
        if( !inDecimal ) {
            it ++ ;
            continue ;
        }
        if( s[ it ] >= '5' && k ) {
            if( s[ it - 1 ] == '.' ) {
                printSolveAddOne() ;
                return 0 ;
            } else {
                s[ it - 1 ] ++ ;
            }
            k -- ;
            n = it ;
            it -- ;
            continue ;
        }
        it ++ ;
    }
    cout << s.substr( 0, n ) ;

    return 0;
}
