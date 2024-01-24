#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;

const int N = 10000010;
int tree[N << 2];

void pushup(int p) {
	tree[p] = tree[lp] && tree[rp];
}

bool f = false;
void modify(int p, int L, int R, int l, int r) {
	if(l > R || r < L) return ;
	if(tree[p]) return ;
	if(l <= L && R <= r) {
		tree[p] = 1, f = 1;
		// cout << "target: " << l << " " << r << '\n'; 
		// cout << "find " << L << " " << R << '\n';
		return ;
	}
	int mid = L + R >> 1;
	if(l <= mid) modify(lp, L, mid, l, r);
	if(r > mid) modify(rp, mid + 1, R, l, r);
	pushup(p);
}

int a[1010], b[1010], ans, n, m;
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) cin >> a[i] >> b[i];
	for(int i = m; i; i --) {
		f = false;
		modify(1, 1, n, a[i], b[i]);
		if(f) ans ++;
	}
	cout << ans << '\n';
}
int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}