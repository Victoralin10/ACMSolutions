/**
* Title:            7367 - RATS
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

// C++11
#include <bits/stdc++.h>
#include <regex>
#define MOD 1000000007
#define MAXN 10

using namespace std;

string suma(const string &a, const string &b) {
    int LA = a.size(), LB = b.size(), L = max(LA, LB), carry = 0;
    string x = string(L, '0');
    while(L--) {
        LA--; LB--;
        if(LA >= 0) carry += a[LA] - '0';
        if(LB >= 0) carry += b[LB] - '0';
        if(carry < 10) x[L] = '0' + carry, carry = 0;
        else x[L] = '0' + carry - 10, carry = 1;
    }
    if(carry) x = '1' + x;
    return x;
}

string fix(string &a) {
    int id = 0;
    while (id < a.size() && a[id] == '0') id++;
    return a.substr(id);
}

string next(string &a) {
    string b = a;
    reverse(b.begin(), b.end());
    string sum = suma(a,b);
    sort(sum.begin(), sum.end());
    return fix(sum);
}

bool isCreeper(string &a) {
    return regex_match(a, regex("1233+4444")) ||
            regex_match(a, regex("5566+7777"));
}

int main(int nargs, char **args) {
    int T, K, M;
    string num;

    cin >> T;
    while (T--) {
        cin >> K >> M >> num;

        set <string> st;
        string ans = num;

        string cr = "";
        int ind;

        for(int i = 1;i <= M;++i) {
            if (st.find(ans) != st.end()) {
                cr = "R";
                ind = i;
                break;
            }
            if (isCreeper(ans)) {
                // cout << ans << endl;
                cr = "C";
                ind = i;
                break;
            }
            st.insert(ans);
            if (i < M) {
                ans = next(ans);
            }
        }

        cout << K << " ";
        if (cr == "") cout << ans << endl;
        else cout << cr << " " << ind << endl;
    }

    return 0;
}
