/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

char getD(char c) {
    int x = c - 'A';
    if (x < 15) {
        return x/3 + 2 + '0';
    }
    x -= 16;
    return x/3 + 7 + '0';
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int n;
    map <string, int> cnt;
    string number, xd;

    cin >> n;
    while (n--) {
        cin >> number;
        xd = "";
        for (int i = 0; i < number.size(); i++) {
            if (isdigit(number[i]) || isalpha(number[i])) {
                xd += number[i];
            }
            if (xd.size() == 3) {
                xd += "-";
            }
        }
        for (int i = 0; i < 8; i++) {
            if (isalpha(xd[i])) {
                xd[i] = getD(xd[i]);
            }
        }

        cnt[xd]++;
    }

    int cntd = 0;
    for (map <string, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
        if (it->second > 1) {
            cout << it->first << " " << it->second << endl;
            cntd++;
        }
    }
    
    if (cntd == 0) {
        cout << "No duplicates." << endl;
    }
    // fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
