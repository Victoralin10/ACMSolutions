/**
* Title:            4286 - Equilibrium Mobile
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>

using namespace std;

char buff[1 << 22];
long long v[1 << 18];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int n;
    scanf("%d", &n);

    fgets(buff, sizeof(buff), stdin);
    while (n--) {
        fgets(buff, sizeof(buff), stdin);
        char *p;
        p = buff;
        int c = 0, d = 0;

        while (*p != '\n') {
            if (*p == '[') d++, p++;
            else if (*p == ']') d--, p++;
            else if (isdigit(*p)) {
                long long xd = 0;
                while (isdigit(*p)) {
                    xd = xd*10 + (*p - '0');
                    p++;
                }
                v[c++] = (xd << d);
            } else {
                p++;
            }
        }

        sort(v, v + c);
        int ans = 0;
        for (int i = 0, j = 0; i < c; i++) {
            while (j < c && v[i] == v[j]) j++;
            ans = max(ans, j - i);
        }
        ans = c - ans;

        printf("%d\n", ans);
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
