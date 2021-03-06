/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

int main(int nargs, char **args) {
    clock_t _inicio = clock();

	int t;
	string s;

	cin >> t;
	while (t--) {
		cin >> s;
		int c[] = {0, 0};
		for (int i = 0; i < s.size(); i++) {
			c[s[i] - '0']++;
		}
		puts((c[0] == 1 || c[1] == 1)?"Yes":"No");
	}

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
