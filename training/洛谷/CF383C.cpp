#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double lbd;
// head

const int N = 300010;

int n, m;
int a[N];

struct seg {
  int lup, ldn, rup, rdn, mid, val, lc, rc;
  ll tg, sz;
} tr[N * 6];

void pushup(int p) {
	tr[p].val = max(tr[lp].val, tr[rp].val);
	tr[p].lc = tr[lp].lc;
	tr[p].rc = tr[rp].rc;
  // -- lup, 
	tr[p].lup = tr[lp].lup;
  if (tr[lp].lup == tr[lp].sz && tr[lp].rc < tr[rp].lc)
  	tr[p].lup += tr[rp].lup;
  
  // -- ldn
	tr[p].ldn = tr[lp].ldn;
  if (tr[lp].ldn == tr[lp].sz && tr[lp].rc > tr[rp].lc)
  	tr[p].ldn += tr[rp].ldn;

  // -- rup
  tr[p].rup = tr[rp].rup;
  if (tr[rp].rup == tr[rp].sz && tr[lp].rc < tr[rp].lc)
  	tr[p].rup += tr[lp].rup;
  	
  // -- rdn
	tr[p].rdn = tr[rp].rdn;
	if (tr[rp].rdn == tr[rp].sz && tr[lp].rc > tr[rp].lc)
		tr[p].rdn += tr[lp].rdn;
		
	// -- mid
	tr[p].mid = max(tr[lp].mid, tr[rp].mid);
	if (tr[p].rc != tr[rp].lc) {
	  tr[p].mid = max(tr[p].mid, tr[lp].rup + tr[rp].ldn);
	}
	
	// -- val
	tr[p].val = max({tr[p].mid, tr[p].lup, tr[p].rdn});
}

void settag(int p, int tg) {
	tr[p].lc+=tg;
	tr[p].rc+=tg;
	tr[p].tg+=tg;
}

void pushdown(int p) {
	if (tr[p].tg) {
		settag(lp, tr[p].tg);
		settag(rp, tr[p].tg);
		tr[p].tg = 0;
	}
}

void build(int p, int l, int r) {
	tr[p].sz = r - l + 1;
  if (l == r) {
  	tr[p] = {1, 1, 1, 1, 1, 1, a[l], a[l], 0, tr[p].sz};
  } else {
    int mid = (l + r) / 2;
    build(lp, l, mid);
    build(rp, mid + 1, r);
    pushup(p);
  }
}

void modify(int p, int l, int r, int ql, int qr, int d) {
	pushdown(p);
	if (ql <= l && r <= qr) {
		settag(p, d); 
	} else {
		int mid = (l + r) / 2;
		if (ql <= mid) modify(lp, l, mid, ql, qr, d);
		if (qr > mid) modify(rp, mid + 1, r, ql, qr, d);
		pushup(p);
	}
}

seg query(int p, int l, int r, int ql, int qr) {
	pushdown(p); 
	if (l == r) return tr[p];
	int mid = (l + r) / 2;
	if (ql > mid) return query(rp, mid + 1, r, ql, qr);
	else if (qr <= mid) return query(lp, l, mid, ql, qr);
	else {
		auto L = query(lp, l, mid, ql, qr);
		auto R = query(rp, mid + 1, r, ql, qr);
		seg ans;
		ans.val = max(L.val, R.val);
		ans.lc = L.lc;
		ans.rc = R.rc;
	  // -- lup, 
		ans.lup = L.lup;
	  if (L.lup == L.sz && L.rc < R.lc)
	  	ans.lup += R.lup;
	  
	  // -- ldn
		ans.ldn = L.ldn;
	  if (L.ldn == L.sz && L.rc > R.lc)
	  	ans.ldn += R.ldn;
	
	  // -- rup
	  ans.rup = R.rup;
	  if (R.rup == R.sz && L.rc < R.lc)
	  	ans.rup += L.rup;
	  	
	  // -- rdn
		ans.rdn = R.rdn;
		if (R.rdn == R.sz && L.rc > R.lc)
			ans.rdn += L.rdn;
			
		// -- mid
		ans.mid = max(tr[lp].mid, tr[rp].mid);
		if (L.rc != R.lc) {
		  ans.mid = max(ans.mid, L.rup + R.ldn);
		}
		
		// -- val
		ans.val = max({ans.mid, ans.lup, ans.rdn});
		return ans;
	}
}

void find(int p, int l, int r) {
	pushdown(p);
	if (l == r) {
		cout << tr[p].lc << " "; 
	} else {
		int mid = (l + r) / 2;
		find(lp, l, mid);
		find(rp, mid + 1, r);
		pushup(p);
	}
}

void solve(int CaseT) {
  cin >> n;
  for (int i = 1; i <= n; i++)
  	cin >> a[i];
  build(1, 1, n);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int l, r, d;
		cin >> l >> r >> d;
		modify(1, 1, n, l, r, d);
//		cout << " res: \n";
//		find(1, 1, n); 
//		cout << '\n';
		
		auto res = query(1, 1, n, 1, n);
		cout << res.val << '\n';
//		if (i == 1) {
//			auto res = query(1, 1, n, 1, n);
//			cout << res.val << '\n';
//			cout << res.lc << " " << res.rc << '\n';
//			cout << res.ldn << " " << res.lup << '\n';
//			cout << res.rdn << " " << res.rup << '\n'; 
//		}
//
//		cout << tr[1].val << '\n';
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;
  // cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
