#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int n, num, m;

struct seg {
	int l, r, col, lz;
	#define lp p<<1
	#define rp p<<1|1
} tr[N * 4];

int get_num(int x) {
	int res = 1;
	for(int i = 0; i < x; i ++) res *= 2;
	return res;
}

void pushup(int p) {
	tr[p].col = tr[lp].col | tr[rp].col;
}

void build(int p, int l, int r) {
	tr[p].l = l, tr[p].r = r, tr[p].lz = 0;
	if(l == r) { tr[p].col = 1; return ;}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}

void pushdown(int p) {
	if(tr[p].lz) {
		tr[lp].lz = tr[rp].lz = tr[p].lz;
		tr[lp].col = tr[rp].col = tr[p].lz;
		tr[p].lz = 0;
	}
}

void modify(int p, int l, int r, int c) {
	if(l > tr[p].r || r < tr[p].l) return ;
	if(l <= tr[p].l && r >= tr[p].r) {
		int t = get_num(c - 1);
		tr[p].col = t, tr[p].lz = t;
		return ;
	}
	pushdown(p);
	modify(lp, l, r, c), modify(rp, l, r, c);
	pushup(p);
}

int query(int p, int l, int r) {
	if(l > tr[p].r || r < tr[p].l) return 0;
	if(l <= tr[p].l && r >= tr[p].r) return tr[p].col;
	pushdown(p);
	int val = 0;
	val = val | query(lp, l, r);
	val = val | query(rp, l, r);
	return val;
}

void print(int ans) {
	int cnt = 0;
	while(ans) {if(ans&1) cnt ++; ans >>= 1;}
	cout << cnt << '\n';
}

void solve() {
	cin >> n >> num >> m;
	build(1, 1, n);
	while(m --) {
		char op[3]; cin >> op;
		if(op[0] == 'C') {
			int a, b, c; cin >> a >> b >> c;
			if(a > b) swap(a, b);
			modify(1, a, b, c);
		}
		else {
			int a, b; cin >> a >> b;
			if(a > b) swap(a, b);
			int ans = query(1, a, b);
			print(ans);
		}
	}
}

int main () {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
	return 0;
}