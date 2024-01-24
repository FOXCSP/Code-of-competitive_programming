#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int n, m;

struct Treap {
	int l, r;
	int val, dat;
	int cnt, sz;
} tr[N];

int root, tot, INF = 1 << 30;

int New(int val) {
	++tot;
	tr[tot].val = val;
	tr[tot].dat = rand();
	tr[tot].cnt = tr[tot].sz = 1;
	return tot;
}

void update(int p) {
	tr[p].sz = tr[tr[p].l].sz + tr[tr[p].r].sz + tr[p].cnt;
}

void zig(int &p) { // 右旋
	int q = tr[p].l;
	tr[p].l = tr[q].r, tr[q].r = p, p = q;
	update(tr[p].r), update(p);
}

void zag(int &p) { // 左旋
	int q = tr[p].r;
	tr[p].r = tr[q].l, tr[q].l = p, p = q;
	update(tr[p].l), update(p);
}


void build() {
	New(-INF), New(INF);
	root = 1; tr[1].r = 2;
	update(root);
	if (tr[1].val < tr[2].val) zag(root);
}

int GetId(int p, int val) {
	if (p == 0) return 0;
	if (val == tr[p].val) return tr[tr[p].l].sz + 1;
	else if (val < tr[p].val) return GetId(tr[p].l, val);
	else return GetId(tr[p].r, val) + tr[tr[p].l].sz + tr[p].cnt;
}

int GetVal(int p, int id) {
	if (p == 0) return INF;
	if (tr[tr[p].l].sz >= id) return GetVal(tr[p].l, id);
	else if (tr[tr[p].l].sz + tr[p].cnt >= id) return tr[p].val;
	else return GetVal(tr[p].r, id - tr[p].cnt - tr[tr[p].l].sz);
}

void insert(int &p, int val) {
	if (p == 0) {
		p = New(val);
		return ;
	}
	if (val == tr[p].val) {
		tr[p].cnt++, update(p);
		return ;
	}
	if (val < tr[p].val) {
		insert(tr[p].l, val);
		if (tr[p].dat < tr[tr[p].l].dat) zig(p); // 右旋, 不满足堆的性质
	} else {
		insert(tr[p].r, val);
		if (tr[p].dat < tr[tr[p].r].dat) zag(p); // 左旋, 不满足堆的性质
	}
	update(p);
}

int GetPre(int val) {
	int ans = 1; // a[1].val = -INF
	int p = root;
	while (p) {
		if (val == tr[p].val) {
			// 找到了, 则一直向左儿子的右儿子走
			if (tr[p].l > 0) {
				p = tr[p].l;
				while (tr[p].r > 0) p = tr[p].r;
				ans = p;
			}
			break;
		}
		if (tr[p].val < val && tr[p].val > tr[ans].val) ans = p;
		p = tr[p].val > val ? tr[p].l : tr[p].r;
	}
	return tr[ans].val;
}

int GetNext(int val) {
	int ans = 2; // tr[2].val = INF
	int p = root;
	while (p) {
		if (val == tr[p].val) {
			if (tr[p].r > 0) {
				p = tr[p].r;
				while (tr[p].l > 0) p = tr[p].l;
				ans = p;
			}
			break;
		}
		if (tr[p].val > val && tr[p].val < tr[ans].val) ans = p;
		p = tr[p].val > val ? tr[p].l : tr[p].r;
	}
	return tr[ans].val;
}

void Remove(int &p, int val) {
	if (p == 0) return ;
	if (val == tr[p].val) {
		if (tr[p].cnt > 1) {
			tr[p].cnt--, update(p);
			return ;
		}
		if (tr[p].l || tr[p].r) {
			if (tr[p].r == 0 || tr[tr[p].l].dat > tr[tr[p].r].dat)
				zig(p), Remove(tr[p].r, val);
			else
				zag(p), Remove(tr[p].l, val);
			update(p);		
		} else p = 0;
		return ;
	}
	val < tr[p].val ? Remove(tr[p].l, val) : Remove(tr[p].r, val);
	update(p);
}

void solve() {
	cin >> n;
	build();
	for (int i= 1; i <= n; i++) {
		int op, x; cin >> op >> x;
		if (op == 1) insert(root, x);
		if (op == 2) Remove(root, x);
		if (op == 3) cout << GetId(root, x) - 1 << '\n';
		if (op == 4) cout << GetVal(root, x + 1) << '\n';
		if (op == 5) cout << GetPre(x) << '\n';
		if (op == 6) cout << GetNext(x) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}