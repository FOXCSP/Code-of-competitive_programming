#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
#define P(T) pair<T, T> 
using namespace std;
typedef long long ll;
const int N = 100010;
const ll mod = 1000000007;
// 1. 线段树统计的是每个区间字符出现的次数 
// 2. 先将每个区间的字符数查出来， 然后根据 k, 升序或降序平摊
// 如果k是升序，那么 if: cnt[a]=2, 就要占住 l, l+1两个位置, 如果是降序，那么就占住 r-1, r两个位置
// 这样对于单次操作[l, r], 时间复杂度为 26log(len)
// 总复杂度在 26nlogn ? 

int n, m;
char c[N];

struct seg {
	int cnt[26];
	int tg, sz;
} tr[N * 8];

void pushup(int p) {
	for (int i = 0; i < 26; i++)
		tr[p].cnt[i] = tr[lp].cnt[i] + tr[rp].cnt[i];
}

void settag(int p, int tg) {
	int len = tr[p].sz;
	for (int i = 0; i < 26; i++)
		tr[p].cnt[i] = 0;
	tr[p].cnt[tg] = tr[p].sz;
	tr[p].tg = tg;
}

void pushdown(int p) {
	if (tr[p].tg != -1) {
		settag(lp, tr[p].tg);
		settag(rp, tr[p].tg);
		tr[p].tg = -1;
	}
}

void build(int p, int l, int r) {
	tr[p].sz = r - l + 1;
	tr[p].tg = -1;
	if (l == r) {
		tr[p].cnt[c[l] - 'a']++;
	} else {
		int mid = (l + r) / 2;
		build(lp, l, mid);
		build(rp, mid + 1, r);
		pushup(p);
	}
}

// 将[ql, qr]中的数全设置为 k 
void modify(int p, int l, int r, int ql, int qr, int k) {
	pushdown(p);
	if (ql <= l && r <= qr) {
		settag(p, k);
	} else {
		int mid = (l + r) / 2;
		if (ql <= mid) modify(lp, l, mid, ql, qr, k);
		if (qr > mid) modify(rp, mid + 1, r, ql, qr, k);
		pushup(p);
	}
}

// 查询 [ql, qr] 中 k的数量 
int query(int p, int l, int r, int ql, int qr, int k) {
	pushdown(p);
	if (ql <= l && r <= qr) {
		return tr[p].cnt[k];
	} else {
		int mid = (l + r) / 2;
		if (qr <= mid) return query(lp, l, mid, ql, qr, k);
		else if (ql > mid) return query(rp, mid + 1, r, ql, qr, k);
		else return query(lp, l, mid, ql, qr, k) + query(rp, mid + 1, r, ql, qr, k);
	}
}

char ans[N];
int len = 0;
void find(int p, int l, int r, int ql, int qr) {
	pushdown(p);
	if (l == r) {
		char ch;
		for (int i = 0; i < 26; i++)
			if (tr[p].cnt[i] == 1) {
				ch = char(i + 'a');
				break;
			}
		ans[++len] = ch;
	} else {
		int mid = (l + r) / 2;
		if (ql <= mid) find(lp, l, mid, ql, qr);
		if (qr > mid) find(rp, mid + 1, r, ql, qr);
		pushup(p);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	cin >> c + 1;
	
	build(1, 1, n);
	
	for (; m--; ) {
		int l, r, k;
		cin >> l >> r >> k;
		k++;
		if (k == 1) {
			// dec
			int num[26] = {0}, now = l;
			for (int i = 0; i < 26; i++)
				num[i] = query(1, 1, n, l, r, i);
	
			for (int i = 25; i >= 0; i--) {
				if (num[i] == 0) continue;
				modify(1, 1, n, now, now + num[i] - 1, i);
				now = now + num[i];
			}
		} else {
			// asc
			int num[26] = {0}, now = l;
			for (int i = 0; i < 26; i++)
				num[i] = query(1, 1, n, l, r, i);
				
			for (int i = 0; i < 26; i++) {
				if (num[i] == 0) continue;
				modify(1, 1, n, now, now + num[i] - 1, i);
				now = now + num[i];
			}
		}
	}
	find(1, 1, n, 1, n);
	ans[++len] = '\0';
	cout << ans + 1 << '\n';
	return 0;
}

