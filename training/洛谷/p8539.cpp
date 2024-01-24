#include <bits/stdc++.h>
#define lp p<<1
#define rp p<<1|1
using namespace std;
using pii = pair<int, int>;
const int N = 2000010;

struct SegT {
	int l, r, id, mx;
	#define l(x) tree[x].l;
	#define r(x) tree[x].r;
	#define id(x) tree[x].id;
	#define mx(x) tree[x].mx;
} tree[N * 4];
int a[N], b[N], n, m, v;
pair<int, int> ans;

void push_up(int p) {
	mx(p) = max(mx(lp), mx(rp));
}

void build(int p, int l, int r) {
	l(p) = l, r(r) = r;
	if(l == r) { mx(p) = a[l], id(p) = l; return ;}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	push_up(p);
}

void push_down(int p) {}

void change(int p, int x, int v) {
	push_down(p);
	if(l(p) == r(p)) {
		mx(p) = mx(p) + v;
		return ;
	}
	int mid = l(p) + r(p) >> 1;
	if(x <= mid) change(lp, x, v);
	if(x > mid) change(rp, x, v);
	push_up(p);
}

pii query(int p, int x) {

}


void solve() {
	cin >> n >> m >> v;
	for(int i = 1;i <= n; i ++) cin >> a[i], b[i] = a[i];
	build(1, 1, n);
	while(m --) {
		int x, k;
		cin >> x >> k;
		if(n - x + 1 < k) ans.first ^= 0, ans.second += 0;
		else {
			// 考虑 1 ~ x-1位
			pii maxx = {-1, -1};
			for(int i = 1;i <= x - 1; i ++) {
				auto res = query(1, i);
				change(1, x, v); // 修改
				maxx = max(maxx, res);
			}
			// 恢复现场
			for(int i = 1; i < x; i ++) {
				reset(1, i, a[i]);
			}

			if(a[maxx.second] >= maxx.first) 
		}
	}
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}