/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

#define piii pair <int, pair <int, int> >

int main(int nargs, char **args) {
    //clock_t _inicio = clock();

    priority_queue <piii > PQ;
    string reg;
    int qnum, period, k;

    while (cin >> reg) {
        if (reg == "#") break;
        cin >> qnum >> period;
        PQ.push(make_pair(-period, make_pair(-qnum, period)));
    }

    cin >> k;
    while (k--) {
        piii tp = PQ.top();
        PQ.pop();

        cout << -tp.second.first << endl;
        tp.first -= tp.second.second;
        PQ.push(tp);
    }

    //fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
