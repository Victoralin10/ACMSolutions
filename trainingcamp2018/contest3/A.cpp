#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/*********************************/

int C[10];
string s, r = "MDCLXVI";
string d[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int v[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

string tor(int n) {
    string ans = "";
    for (int i = 0; i < 13; i++) {
        while (n >= v[i]) {
            ans += d[i];
            n -= v[i];
        }
    }
    return ans;
}

bool isp(string s) {
    for (int i = 0; i < r.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < s.size(); j++) {
            cnt += (s[j] == r[i]);
        }
        if (cnt > C[i]) return false;
    }
    return true;
}

int main() {
	getline(cin , s);
	for (int i = 0; i < s.size(); i++) {
		s[i] = toupper(s[i]);
	}
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (r[i] == s[j]) {
				C[i]++;
			}
		}
	}

    string ans = "";
    for (int i = 1; i < 4000; i++) {
        string mr = tor(i);
        if (isp(mr) && mr.size() >= ans.size()) {
            ans = mr;
        }
    }
    cout << ans << endl;

	return 0 ;
}