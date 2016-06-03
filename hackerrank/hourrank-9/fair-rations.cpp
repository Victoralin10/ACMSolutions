/**
* Title:            Fair Rations
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int N;
    cin >> N;
            
    vector<int> B(N);
    for(int B_i = 0;B_i < N;B_i++){
        cin >> B[B_i];
    }
                    
    int ans = 0;
    for (int i = 0;i + 1 < N; i++) {
        if ((B[i]&1) == 1) {
            ans += 2;
            B[i+1]++;
        }                                 
    }
                            
    if ((B[N-1]&1) == 1) {
        cout << "NO" << endl;
    } else {
        cout << ans << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
