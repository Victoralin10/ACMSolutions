/**
* Title:            7359 - Sum Kind Of Problem
* Author:           Diego Mansilla
* Email:            dmansilla07@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

long long suma(int a, int u, int n) {
    return (1LL*(1LL*a + u)*n)/2LL;
}

int main(int nargs, char **args) {
    int T, K, N;
    cin>>T;
    while (T--) {
        cin>>K>>N;
        cout<<K<<" "<<suma(1, N, N)<<" "<<suma(1, 2*N-1, N)<<" "<<suma(2, 2*N, N)<<endl;
    }
    return 0;
}
