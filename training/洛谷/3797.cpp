#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
#define pb push_back
#define vec vector
#define all(T) T.begin(), T.end() 
using namespace std;
typedef long long ll;
typedef long double ldb;
// head
const int N = 200010;
int n, m;
int a[N];

struct seg {
	int  val;
	char lc, rc;
} tr[N * 4];

void pushup(int p) {
	tr[p].val = tr[lp].val + tr[rp].val;
	tr[p].lc = tr[lp].lc;
	tr[p].rc = tr[rp].rc;
	if (tr[lp].rc == '(' && tr[rp].lc == ')') 
		tr[p].val++;
	if (tr[lp].lc == '#') tr[p].lc = tr[rp].lc;
	if (tr[rp].rc == '#') tr[p].rc = tr[lp].rc;
}

void build(int p, int l, int r) {
	if (l == r) {
		tr[p].lc = tr[p].rc = '#';
		if (l == 1) tr[p].rc = tr[p].lc = '(';
		if (l == n) tr[p].lc = tr[p].rc = ')';
		tr[p].val = 0;
	} else {
		int mid = (l + r) / 2;
		build(lp, l, mid);
		build(rp, mid + 1, r);
		pushup(p); 
	}
}
/*
8 5
1 3 )
1 4 (
2 1 8
2 2 4
2 1 4
(*******) -> (*)(***)

2
0
1
*/
void modify(int p, int l, int r, int x, char c) {
	if (l == r) {
		if (c == ')') tr[p].lc = tr[p].rc = ')';
		else if (c == '(') tr[p].lc = tr[p].rc = '(';
		else tr[p].lc = tr[p].rc = '#'; 
	} else {
		int mid = (l + r) / 2;
		if (x > mid) modify(rp, mid + 1, r, x, c);
		else if (x <= mid) modify(lp, l, mid, x, c);
		pushup(p); 
	}
}

seg query(int p, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr)
		return tr[p];
	int mid = (l + r) / 2;
	if (qr <= mid) return query(lp, l, mid, ql, qr);
	else if (ql > mid) return query(rp, mid + 1, r, ql, qr);
	else {
		auto L = query(lp, l, mid, ql, qr);
		auto R = query(rp, mid + 1, r, ql, qr);
		seg ret = {0, 0, 0};
		ret.val = L.val + R.val;
		ret.lc = L.lc;
		ret.rc = R.rc;
		if (L.rc == '(' && R.lc == ')') ret.val++;
		if (L.lc == '#') ret.lc = R.lc;
		if (R.rc == '#') ret.rc = L.rc;
		return ret; 
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	build(1, 1, n);
//	cout << tr[1].val << '\n';
	
	for (; m--; ) {
		int op, l, r, x;
		char c;
		cin >> op;
		if (op == 1) {
			cin >> x >> c;
			modify(1, 1, n, x, c);
		} else {
			cin >> l >> r;
			auto res = query(1, 1, n, l, r);
			cout << res.val << '\n';
		}
	}
	
	return 0;
} 
