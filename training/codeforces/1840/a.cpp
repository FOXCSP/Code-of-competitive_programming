#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())

using namespace std;

int st[26];
void solve() {
	memset(st, 0, sizeof st);
	int n;
	string s, ans = "";
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		ans.push_back(s[i]);
		int res = -1;
		for (int j = i + 1; j < n; j++) {
			if (s[j] == s[i]) {
				res = j;
				break;
			}
		}
		if (res == -1) break;
		i = res;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int _ = 1;
	cin >> _;
	for (; _--; ) {
		solve();
	}
	
	return 0;
}
