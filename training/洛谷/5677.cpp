#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 300010;
int n, m;
int a[N];
int t[N], s[N];
struct name {
	int l, r, i;
	bool operator < (const name & B) const {
		return l < B.l;
	}
} query[N];

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);	
	a[n + 1] = 2e9; a[0] = -2e9;
	for(int i = 1;i <= n;i ++) {
		if(a[i] - a[i - 1] < a[i + 1] - a[i]) t[i - 1] += 1;
		else if(a[i] - a[i - 1] > a[i + 1] - a[i]) s[i + 1] += 1;
		else t[i - 1] += 1, s[i + 1] += 1;
	}

	for(int i = 1;i <= n; i ++) cout << s[i] << " \n"[i == n];
	for(int i = 1;i <= n; i ++) cout << t[i] << " \n"[i == n];

	for(int i = 0;i <= n + 1; i ++)
		t[i] += t[i - 1], s[i] += s[i - 1];

	for(int i = 1;i <= m; i ++) {
		int l, r;
		cin >> l >> r;
		query[i] = {l, r, i};
	}
	sort(query + 1, query + m + 1);
	ll ans = 0;
	for(int i = 1;i <= m;i ++) {
		int l = query[i].l, r = query[i].r, id = query[i].i;
		int x = s[r] - s[l];
		x += (t[r - 1] - t[l - 1]);
		cout << s[r] - s[l] << " sss\n";
		cout << t[r - 1] - t[l - 1] << " ttt\n";
		// cout << x << "\n";
		ans += x * id;
	}
	cout << ans << '\n';
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}