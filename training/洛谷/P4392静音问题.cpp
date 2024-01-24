#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
int read() {
	int s = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while('0' <= c && c <= '9') s = s * 10 + c - '0', c = getchar();
	return s * f;
}

int n, m, c;

struct Seg {
	int l, r;
	int high, low;
	#define lp (p<<1)
	#define rp (p<<1|1)
} tr[N << 2];

void pushup(int p) {
	tr[p].high = max(tr[lp].high, tr[rp].high);
	tr[p].low = min(tr[lp].low, tr[rp].low);
}
void build(int p, int l, int r) {
	tr[p].l = l, tr[p].r = r;
	if(l == r) {
		cin >> tr[p].high;
		tr[p].low = tr[p].high;
		return ;
	}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}

pair<int,int> query(int p, int l, int r) {
	if(l > tr[p].r || r < tr[p].l) return {-2e9, 2e9};
	if(l <= tr[p].l && tr[p].r <= r) return {tr[p].high, tr[p].low};
	int mid = tr[p].l + tr[p].r >> 1;
	int x = 2e9, y = -2e9;
	if(l <= mid) { 
		auto res1 = query(lp, l, r); x = min(x, res1.second); y = max(y, res1.first);
	}
	if(r > mid) {
		auto res2 = query(rp, l, r); x = min(x, res2.second); y = max(y, res2.first);
	}
	return {y, x};
}

void solve() {
	n = read(), m = read(), c = read();
	build(1, 1, n);
	bool f = false;
	for(int i = 1; i + m - 1 <= n; i ++) {
		int j = i + m - 1;
		auto t = query(1, i, j);
		// cout << t.first << " " << t.second << "\n";
		if(t.first - t.second > c) continue;
		cout << i << '\n';
		f = true;
	}
	if(!f) {cout << "NONE\n";}
}

int main() {
	solve();
	return 0;
}