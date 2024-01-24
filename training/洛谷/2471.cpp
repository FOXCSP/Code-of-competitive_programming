#include <bits/stdc++.h>
#define lp p<<1
#define rp p<<1|1
using namespace std;

const int N = 100010;

struct Seg {
	int l, r, Max;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define Max(x) tree[x].Max
} tree[N * 4];

int n, a[N], b[N],m, idx = 1;
map<int,int> id;

void pushup(int p) {
	Max(p) = max(Max(lp), Max(rp));
}

void build(int p, int l, int r) {
	l(p) = l, r(p) = r;
	if(l == r) { Max(p) = a[l]; return ;}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}


int query(int p, int l, int r) {
	if(l <= l(p) && r(p) <= r) return Max(p);
	int mid = l(p) + r(p) >> 1;
	int val = -1;
	if(l <= mid) val = max(val, query(lp, l, r));
	if(r > mid) val = max(val, query(rp, l, r));
	return val;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		int y, r;
		cin >> y >> r;
		id[y] = i;
		a[i] = r;
		b[i] = y;
	}
	build(1, 1, n);
	b[n + 1] = 2e9;
	id[2e9] = n + 1;
	cin >> m;
	while(m --) {
		int x, y;
		cin >> y >> x;
		if(x <= y) cout << "false\n";
		else if(!id.count(x) && !id.count(y)) cout << "maybe\n";
		else if(!id.count(x)) {
			x = *lower_bound(b + 1, b + n + 2, x);
			// cout << x << '\n';
			int t = query(1, id[y] + 1, id[x] - 1);
			if(a[id[y]] <= t) cout << "false\n";
			else cout << "maybe\n";
		}
		else if(!id.count(y)) {
			y = *lower_bound(b + 1, b + n + 1, y);
			int t = query(1, id[y], id[x]);
			// cout << query(1, id[y], id[x] - 1) << " " << t << "\n";
			if(t == a[id[x]] && query(1, id[y], id[x] - 1) < t) cout << "maybe\n";
			else cout << "false\n";
		}
		else {
			if(a[id[y]] < a[id[x]]) cout << "false\n";
			else {
				int t = query(1, id[y] + 1, id[x]);
				if(t == a[id[x]]) {
					int d = id[x] - id[y];
					if(query(1, id[y] + 1, id[x] - 1) == t) cout << "false\n";
					else if(x - y > d) cout << "maybe\n";
					else cout << "true\n";
				}
				else cout << "false\n";
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}