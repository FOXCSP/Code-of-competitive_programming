#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
int f[N];
string s[N];
void solve() {
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1;i <= n;i ++) {
		cin >> s[i];
		f[i] = 1;
		for(int j = i - 1; j; j --)
			if(s[i].find(s[j]) == 0) f[i] = max(f[i], f[j] + 1);
	}
	for(int i = 1;i <= n;i ++) ans = max(ans, f[i]);
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	solve();
	return 0;
}