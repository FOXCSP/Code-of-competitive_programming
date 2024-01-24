#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define PII pair<int,int>
#define PLL pair<ll, ll>
#define VI vector<int>
#define SZ(x) ((int)x.size())
#define VL vector<ll>;
#define VPP vector<PII>
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
inline ll read() {
	ll s=0,f=1; char c = getchar();
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while ('0'<= c&&c<='9') {s=s*10+c-'0';c=getchar();}
	return s*f;
}
void print(ll x) {if (!x) return ; if (x>9) print(x/10); putchar(x%10+'0');}
const int Mod = 1e9+7;
// --head--

const int N = 100010;
int n, m;
char S[N];

struct Seg{
	char mx, mn;
	int cnt[30], tag;
	Seg operator + (const Seg& B) const {
		Seg res;
		res.mx = max(mx, B.mx);
		res.mn = min(mn, B.mn);
		res.tag = tag | B.tag;
		for (int i = 1; i <= 26; i++) res.cnt[i] = cnt[i] + B.cnt[i];
		return res;
	}
} tr[N * 4];

void pushup(int p) {
	tr[p] = tr[lp] + tr[rp];
	if (tr[lp].mx > tr[rp].mn) tr[p].tag = 1;
}

void build(int p, int l, int r) {
	if (l == r) {
		tr[p].mx = tr[p].mn = S[l];
		tr[p].cnt[S[l] - 'a' + 1] = 1, tr[p].tag = 0;
	} else {
		int mid = (l + r) / 2;
		build(lp, l, mid), build(rp, mid + 1, r);
		pushup(p);
	}
}

void modify(int p, int l, int r, int x, char d) {
	if (l == r) {
		tr[p].cnt[tr[p].mx - 'a' + 1] = 0;
		tr[p].mx = tr[p].mn = d;
		tr[p].cnt[d - 'a' + 1] = 1;
		return ;
	}
	int mid = (l + r) / 2;
	if (x <= mid) modify(lp, l, mid, x, d);
	if (x > mid) modify(rp, mid + 1, r, x, d);
	pushup(p);
}

Seg query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return tr[p];
	}
	int mid = (l + r) / 2;
	if (L > mid) return query(rp, mid + 1, r, L, R);
	else if (R <= mid) return query(lp, l, mid, L, R);
	else {
		auto LL = query(lp, l, mid, L, R);
		auto RR = query(rp, mid + 1, r, L, R);
		auto res = LL + RR;
		if (LL.mx > RR.mn) res.tag = 1;
		return res;
	}
}

int cnt[30];
int main() {
	cin >> n >> S + 1 >> m;
	for (int i = 1; i <= n; i++) {
		cnt[S[i] - 'a' + 1]++;
	}
	build(1, 1, n);
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x; char c;
			cin >> x >> c;
			modify(1, 1, n, x, c);
			cnt[S[x] - 'a' + 1]--;
			S[x] = c;
			cnt[c - 'a' + 1]++;
		} else {
			int l , r;
			cin >> l >> r;
			Seg x = query(1, 1, n, l, r);
			bool f = 0;
			for (int i = 1; i <= 26; i++) {
				if (x.mn - 'a' + 1 < i && i < x.mx - 'a' + 1) {
					if (cnt[i] != x.cnt[i]) {
						f = 1;
						// cout << cnt[i] << " " << x.cnt[i] << '\n';
						break;
					}
				}
			}
			if (x.tag || f) {
				cout << "No\n";
			} else {
				cout << "Yes\n";
			}
		}
	}
	return 0;
}