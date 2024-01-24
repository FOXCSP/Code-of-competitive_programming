// Problem: P5648 Mivik的神力
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5648
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Author: Rufu

#include <bits/stdc++.h>
#define int long long
#define cf int _; cin>>_; while(_--) solve();
using namespace std;
using PII = pair<int,int>;
using ll = long long;

#define lp (p<<1)
#define rp (p<<1|1)

const int N = 500010;

struct seg{
	int l, r;
	int dat, mx, id;
} tr[N << 4];

int n, m;

void pushup(int p) {
	if(tr[lp].mx >= tr[rp].mx)	tr[p].id = tr[lp].id;
	else	tr[p].id = tr[rp].id;
	if(tr[rp].mx < tr[lp].mx) 
		tr[p].dat = tr[lp].dat + (tr[lp].mx) * (tr[rp].r - tr[rp].l + 1);
	else {
		// tr[p].dat = tr[lp].dat + tr[rp].dat;
		tr[p].dat = tr[lp].dat + tr[lp].mx * (tr[rp].id - tr[rp].l) + (tr[rp].r - tr[rp].id + 1) * tr[rp].mx;
	}
}

void build(int p, int l, int r) {
	tr[p].l = l, tr[p].r = r;
	if(l == r) {
		cin >> tr[p].mx; tr[p].dat = tr[p].mx, tr[p].id = l;
		return ;
	}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}

seg query(int p, int l, int r) {
	if(l <= tr[p].l && tr[p].r <= r) return tr[p];
	int mid = tr[p].l + tr[p].r >> 1;
	if(l > mid) return query(rp, l, r);
	else if(r <= mid) return query(lp, l, r);
	else {
		auto L = query(lp, l, r), R = query(rp, l, r);
		seg ret = L;
		if(R.mx < L.mx) ret.dat += L.mx * (R.r - R.l + 1);
		else ret.dat += R.mx * (R.id - R.l) + (R.r - R.id + 1) * R.mx;
		if(ret.mx < R.mx) {
			ret.ix = R.id, ret.mx = R.mx;
		}
		return ret;
	}
}

void solve() {
	cin >> n >> m;
	build(1, 1, n);
	int lastans = 0ll;
	while(m --) {
		int u, v; cin >> u >> v;
		int l = 1 + (u ^ lastans) % n;
		int q = 1 + (v ^ (lastans + 1)) % (n - l + 1);
		// auto t = query(1, l, l + q - 1);
		auto t = query(1, u, v);
		cout << t.dat << '\n';
		lastans = t.dat;
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}