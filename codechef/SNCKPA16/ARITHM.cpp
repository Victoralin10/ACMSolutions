/**
* Title:            Chocolates for Everyone
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t;
    long long n, c;

    cin >> t;
     while (t--) {
         cin >> n >> c;

         bool ok = false;
         if ((2*c)%n == 0) {
             if (n%2 == 0) { //Si n es par
                 long long a = -(n-1)/2, b = 1;
                 a *= (2*c)/n;
                 b *= (2*c)/n;

                 long long xd = -a/(n-1) + 1;
                 a += xd*(n-1);
                 b -= 2*xd;

                 // cout << a << " " << b << endl;
                 ok = b > 0;
             } else if (c%n == 0) {
                 if (n == 1) ok = true;
                 else {
                     long long l = (n-1)/2;
                     long long a = -(l-1), b = 1;
                     a *= (c/n);
                     b *= (c/n);

                     long long xd = -a/l + 1;
                     a += xd*l;
                     b -= xd;

                     // cout << a << " " << b << endl;
                     ok = b>0;
                 }
             }
         }

         puts(ok?"Yes":"No");
     }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
