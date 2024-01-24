#include <bits/stdc++.h>

using namespace std;
int t[26];
void debug(int n) {
	for(int i = 1; i <= n; i ++) cout << t[i] << " \n"[i == n];
}
bool cmp(char a, char b) {
	return a > b;
}
void solve() {
	int n, m; string s;
	cin >> n >> m >> s;
	int q = n / m;
	// sort(s.begin(), s.end());
	memset(t, 0, sizeof t);
	for(auto c : s) {
		t[c - 'a' + 1] ++;
	}
	// debug(n);
	string ans = "";
	for(int i = 1;i <= m; i ++) {
		char ch = 'z', x = 'a';
		int cnt = 0;
		for(int k = 1; k <= 25; k ++) {
			if(t[k] == 0) {
				ch = min(ch, char(k + 'a' - 1));
				break;
			}
			cnt ++; t[k] --;
			x = char(k + 'a' - 1);
			if(cnt == q) break;
		}
		if(ch == 'z') ch = x + 1;
		ans = ans + ch;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int _; cin >> _; while(_ --) solve();
	return 0;
}