#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 128;

bool isEnglish(string s) {
	return s[0] != '#';
}

string s[kMaxN];
int N;

void print(int idx) {
	for(int i=idx+1; i<N; ++i) {
		if (i > idx+1) cout<<" ";
		cout<<s[i];
	}
	if (idx < N-1 && idx != -1) cout<<" ";
	if (idx != -1) cout<<s[idx];
	for(int i=0; i < idx; ++i) {
		cout<<" "<<s[i];
	}
	puts("");
}

int main() {
	int T;
	cin>>T;
	while (T--) {
		cin>>N;
		int idx = -1;
		for(int i=0; i<N; ++i) {
			cin>>s[i];
			if (isEnglish(s[i]))
				idx = i;
		}
		print(idx);
	}
}
