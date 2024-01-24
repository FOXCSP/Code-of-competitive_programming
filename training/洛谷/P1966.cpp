#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 100010, mod = 1e8 - 3;
int c[N], t[N];
int n;

void add(int x, int y) {
	for(; x <= n; x += x & -x) c[x] += y;
}

int ask(int x) {
	int ans = 0;
	for(; x ; x -= x & -x) ans += c[x];
	return ans;
}

struct num {
	int x, id;
} b[N], a[N];

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i].x;
		a[i].id = i;
	}
	for(int i = 1; i <= n; i ++) {
		cin >> b[i].x;
		b[i].id = i;

	}
	sort(a + 1, a + n + 1, [](num a, num b) {
		return a.x < b.x;
	}); 
	sort(b + 1, b + n + 1, [](num a, num b){
		return a.x < b.x;
	});
	for(int i = 1;i <= n;i ++) {
		t[a[i].id] = b[i].id;
	}
	ll ans = 0;
	for(int i = n; i; i --) {
		ans = (ask(t[i] - 1) + ans) % mod;
		add(t[i], 1);
	}
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}