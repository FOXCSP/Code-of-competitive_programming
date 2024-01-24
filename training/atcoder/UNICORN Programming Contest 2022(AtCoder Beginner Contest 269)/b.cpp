#include <bits/stdc++.h>

using namespace std;


string s[13];
void solve() {
	int n = 1;
	while(cin >> s[n]) {
		s[n] = "?" + s[n];
		n ++;
	}
	int a = 0, b = 0, c = 0, d = 0;
	for(int i = 1;i <= n - 1; i ++) {
		for(int j = 1;j <= s[i].size() - 1; j ++ ) {
			if(!a && !b && s[i][j] == '#') a = i, b = j;
			if(s[i][j] == '#') c = i, d = j;
		}
	}

	cout << a << " " << c << "\n" << b << " " << d << '\n';
}


int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}