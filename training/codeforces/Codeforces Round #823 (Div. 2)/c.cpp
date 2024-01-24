#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	char mn = '9';
	for(int i = s.size() - 1; i >= 0; i --) {
		mn = min(s[i], mn);
		if(s[i] > mn) s[i] = min(char(s[i] + 1), '9');
	}
	sort(s.begin(), s.end());
	cout << s << '\n';
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}