#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int n;
char s[N];


void solve() {
	cin >> n;
	cin >> s + 1;
	bool l = false, r = false;
	int t = 1;
	while(t < n) {
		if(s[t] == '1') {
			if(t != 1) l = true;
			break;
		}
		t ++;
	}
	t = n;
	while(t) {
		if(s[t] == '1') {
			if(t != n) r = true;
			break;
		}
		t --;
	}
	cout << (l == true) + (r == true) << '\n';
}

int main () {
	ios :: sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}