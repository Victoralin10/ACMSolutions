/**
* Title:            7361 - Immortal Porpoises
* Author:           Diego Mansilla
* Email:            dmansilla07@gmail.com
**/

#include <bits/stdc++.h>
#define kMod 1000000000
#define MAXN 10

using namespace std;

typedef long long ll;

struct Matrix{
    ll M[2][2];
    Matrix(){
        M[0][0] = M[0][1] = M[1][0] = 1;
        M[1][1] = 0;
    }
    Matrix(ll t) {
        M[0][0] = M[1][1] = 1;
        M[0][1] = M[1][0] = 0;
    }
};

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    for(int i=0; i<2; ++i)
        for(int j=0; j<2; ++j) {
            ll dev = 0;
            for(int r=0; r<2; ++r) {
                dev = (dev + a.M[i][r]*b.M[r][j])%kMod;
                c.M[i][j] = dev %kMod;
            }
        }
    return c;
}

Matrix pow(Matrix a, ll b) {
    Matrix ans(1);
    while (b > 0) {
        if (b%2 == 1) ans = ans*a;
        a = a*a;
        b/=2LL;
    }
    return ans;
}

int main(int nargs, char **args) {
    int T, K;
    ll N;
    cin>>T;
    while (T--) {
        cin>>K>>N;
        Matrix mat;
        mat = pow(mat, N-1);
        cout<<K<<" "<<mat.M[0][0]<<endl;
    }
    return 0;
}
