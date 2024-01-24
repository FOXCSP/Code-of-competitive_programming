// 注意在合并时的 l, r 更新问题

#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 500010;

int a[N], n;

struct Seg {
	int ml, mf, way, l, r;
	Seg operator + (const Seg &b) const { // merge [a], [b]
		Seg ans;
		if(!b.mf && !b.ml) {
			ans = *this;
			ans.r = b.r;
			return ans;
		}
		if(!mf && !ml) {
			ans = b;
			ans.l = l;
			return ans;
		}
		if(ml > b.mf) {
			ans.mf = mf;
			ans.ml = ml - b.mf + b.ml;
			ans.way = ((way >> b.mf) << b.ml) + b.way;
		}
		else {
			ans.mf = mf - ml + b.mf;
			ans.ml = b.ml;
			ans.way = b.way;
		}
		ans.l = l, ans.r = b.r;
		return ans;
	}
    #define ml(x) tree[x].ml
    #define mf(x) tree[x].mf
    #define way(x) tree[x].way
    #define tr(x) tree[x]
    #define l(x) tree[x].l
    #define r(x) tree[x].r
} tree[N<<2];

void build(int p, int l, int r) {
	l(p) = l, r(p) = r;
	if(l == r) {
		if(a[l] == 1) {
			ml(p) = 1;
		}
		if(a[l] == 2) {
			ml(p) = 1;
			way(p) = 1;
		}
		if(a[l] == 3) {
			mf(p) = 1;
		}
		return ;
	}
	int mid = l + r >> 1;
	build(p<<1, l, mid), build(p<<1|1, mid+1, r);
	tr(p) = tr(p<<1) + tr(p<<1|1);
}

void change(int p, int x, int y) {
	if(x < l(p) || x > r(p)) return ;
	if(l(p) == r(p)) {
		tr(p) = {0, 0, 0, l(p), r(p)};
		if(y == 1) {
			ml(p) = 1;
		}
		if(y == 2) {
			ml(p) = 1;
			way(p) = 1;
		}
		if(y == 3) {
			mf(p) = 1;
		}
		return ;
	}
	int mid = l(p) + r(p) >> 1;
	if(x > mid) change(p<<1|1, x, y);
	else if(x <= mid) change(p<<1, x, y);
	tr(p) = tr(p<<1) + tr(p<<1|1);
}

Seg query(int p, int l, int r) {
	Seg ans = (Seg){0, 0, 0, l(p), r(p)};
	if(l(p) > r || r(p) < l) return ans;
	if(l <= l(p) && r >= r(p)) return tr(p);
	return (query(p<<1, l, r) + query(p<<1|1, l, r));
}

void solve() {
	int m, q;
	cin >> n >> m >> q;
	for(int i = 1;i <= m; i ++) cin >> a[i];
	build(1, 1, m);
	while(q --) {
		int op;
		cin >> op;
		if(op == 1) {
			ll s;
			int l, r;
			cin >> s >> l >> r;
			auto t = query(1, l, r);
			cout << (max(1ll, (s >> t.mf)) << t.ml) + t.way << '\n';
		}
		else {
			int x, y;
			cin >> x >> y;
			change(1, x, y);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}