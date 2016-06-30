/**
* Title:            1306. Sequence Median
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <cstdio>
#include <queue>

using namespace std;

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int n;
    scanf("%d", &n);

    priority_queue <int> Q;
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        Q.push(x);
        if (Q.size() > n/2 + 1) {
            Q.pop();
        }
    }

    double ans = Q.top();
    if ((n&1) == 0) {
        Q.pop();
        ans += Q.top();
        ans /= 2.0;
    }

    printf("%.1f\n", ans);

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
