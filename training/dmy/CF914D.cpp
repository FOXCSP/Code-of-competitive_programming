#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
#define P(T) pair<T, T> 
#define vec vector
#define fi first
#define se second
#define pb push_back
#define all(T) T.begin(), T.end()
using namespace std;
typedef long long ll;
const int N = 500010;
const ll mod = 1000000007;

int n, m;

struct seg {
	int val;
} tr[N * 4];

void pushup(int p) {
	tr[p].val = __gcd(tr[lp].val, tr[rp].val);
} 

void build(int p, int l, int r) {
	if (l == r) {
		cin >> tr[p].val;
	} else {
		int mid = (l + r) / 2;
		build(lp, l, mid);
		build(rp, mid + 1, r);
		pushup(p);
	}
}

void modify(int p, int l, int r, int x, int d) {
	if (l == r) {
		tr[p].val = d;
	} else {
		int mid = (l + r) / 2;
		if (x <= mid) modify(lp, l, mid, x, d);
		else modify(rp, mid + 1, r, x, d);
		pushup(p);
	}
}

int ans;
void query(int p, int l, int r, int ql, int qr, int d) {
	if (ans > 1) return ;
	if (l == r) {
		ans++;
		return ;
	}
	int mid = (l + r) / 2;
	if (ql <= mid && (tr[lp].val % d != 0)) query(lp, l, mid, ql, qr, d);
	if (qr > mid  && (tr[rp].val % d != 0)) query(rp, mid + 1, r, ql, qr, d);
}

void db(int p, int l, int r) {
	if (l == r) {
		cout << tr[p].val << " ";
	} else {
		int mid = (l + r) / 2;
		db(lp, l, mid);
		db(rp, mid + 1, r);
		pushup(p);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	build(1, 1, n);

	cin >> m;
	for (; m--; ) {
		int op, l, r, x;
		cin >> op;
		if (op == 1) {
			cin >> l >> r >> x;
			ans = 0;
			query(1, 1, n, l, r, x);
			cout << (ans <= 1 ? "YES" : "NO") << '\n';	
		} else {
			cin >> l >> x;
			modify(1, 1, n, l, x);
		}
	}
	return 0;
}
