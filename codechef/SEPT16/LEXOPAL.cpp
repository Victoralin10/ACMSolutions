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
		bool ok = 1;
		for (int i = 0, j = (int)s.size() - 1; i <= j && ok; i++, j--) {
			if (s[i] == '.' && s[j] == '.') {
				s[i] = s[j] = 'a';
			} else if (s[i] == '.') {
				s[i] = s[j];
			} else if (s[j] == '.') {
				s[j] = s[i];
			} else if (s[i] != s[j]) {
				ok = 0;
			}
		}
		cout << (ok?s:"-1") << endl;
	}

    //fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
