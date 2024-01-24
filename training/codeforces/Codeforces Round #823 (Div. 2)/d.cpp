#include <bits/stdc++.h>

using namespace std;

int t[30][30];
int cnt[30];
void solve() {
	memset(t, 0, sizeof t);
	memset(cnt, 0, sizeof cnt);
	int n; cin >> n;
	string a, b; cin >> a >> b;
	a = "@" + a;
	b = "@" + b;
	int same = 0;
	bool no = true;
	for(int i = 1; i <= n;i ++) if(a[i] == b[n - i + 1]) cnt[a[i] - 'a'] ++; else {
		int x = min(a[i] - 'a', b[n - i + 1] - 'a');
		int y = max(a[i] - 'a', b[n - i + 1] - 'a');
		t[x][y] ++;
	}
	for(int i = 0; i <= 25; i ++) if(cnt[i]&1) { same ++;}
	for(int i = 0; i <= 25; i ++) for(int j = 0;j <= 25; j ++) if(t[i][j]&1) { no = false; break;}
	if((n % 2 == 0 && same ) || (n % 2 && same > 1) || !no) cout << "NO\n";
	else cout << "YES\n";
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}