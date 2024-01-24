#include <bits/stdc++.h>

using namespace std;

string s;
int get(char c) {
	return c - 'a' + 1;
}

void solve() {
	int n; cin >> n >> s;
	s = "0" + s;
	map<int, int> mp, rp;
	int res = 1;
	for(int i = 1;i <= n; i ++) {
		int t = get(s[i]);
		if(mp[t]) continue;
		for(int j = 1; j <= 26; j ++) {
			if(j == t || rp[j]) continue;
			int k = j, cnt = 0;
			while(mp[k]) k = mp[k], cnt ++;
			if(k == t) {
				if(cnt == 25) {mp[t] = j, rp[j] ++; break;}
				else continue;
			}
			mp[t] = j; rp[j] ++;
			break;
		}
	}
	for(int i = 1;i <= n; i ++) {
		cout << char(mp[get(s[i])] + 'a' - 1);
	}
	cout << '\n';
}


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T; while(T --) solve();
	return 0;
}
