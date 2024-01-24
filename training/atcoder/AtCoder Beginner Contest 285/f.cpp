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
int cnt[30];
int n, m;
string S;
VPP que;
int tt;
void solve() {
	cin >> n >> S >> m;
	for (int i = 0; i < n; i++) {
		cnt[S[i] - 'a' + 1]++;
		if (!tt || que.back().fi != S[i] - 'a' + 1) que.pb({S[i] - 'a' + 1, 1});
		else que.back().se++;
	}
	while (m--) {
		int op, l;
		cin >> op >> l;
		if (op == 1) {
			char c; cin >> c;
			cnt[S[l - 1] - 'a' + 1]--;
			cnt[c - 'a' + 1]++;
			int k = l;
			for (int i = 0; i < SZ(que); i++) {
				if (que[i].se < k) k -= que[i].se;
				else {
					if (que[i].se == k) {
						que[i].se--;
						if (que[i].se) que.insert(que.begin() + i + 1, {c - 'a' + 1, 1});
						else que[i] = {c - 'a' + 1, 1};
					} else {
						int t = que[i].se;
						que[i].se -= k;
						if (k == 1) {
							que[i] = {c - 'a' + 1, 1};
							que.insert(que.begin() + i + 1, {que[i].fi, t - que[i].se});
						}
						else { 
							que[i].se = k - 1; 
							que.insert(que.begin() + i + 1, {c - 'a' + 1, 1});
							que.insert(que.begin() + i + 2, {que[i].fi, t - k});
						}
					}
					break;
				}
			}
		} else {
			int r;
			cin >> r;
			VPP res, ans;
			int x = 0, k = r - l + 1;
			for (int i = 1; i <= 26; i++) {
				if (x + cnt[i] < l) x += cnt[i];
				else {
					res.pb({i, (min(x + cnt[i], r) - l + 1)});
					x += cnt[i];
					if (x < r) {
						for (int j = i + 1; j <= 26; j++) {
							if (x + cnt[j] < r) {
								if (cnt[j]) res.pb({j, cnt[j]});
								x += cnt[j];
							} else {
								if (r - x) res.pb({j, r - x});
								break;
							}
						}
					}
					break;
				}
			}
			x = 0;
			for (int i = 0; i < SZ(que); i++) {
				if (que[i].se + x < l) x += que[i].se;
				else {
					ans.pb({que[i].fi, min(x + que[i].se, r) - l + 1});
					x += que[i].se;
					if (x < r) {
						for (int j = i + 1; j < SZ(que); j++) {
							if (x + que[j].se < r) {
								if (que[j].se) ans.pb({que[j].fi, que[j].se});
								x += que[j].se;
							} else {
								if (r - x) ans.pb({que[j].fi, r - x});
								break;
							}
						}
					}
					break;
				}
			}
			// for (auto [a, b] : res) {
			// 	cout << a << " " << b << '\n';
			// }
			// cout << " --\n";
			// for (auto [a, b] : ans) {
			// 	cout << a << " " << b << '\n';
			// }
			if (ans != res) {
				cout << "No\n";
			} else {
				cout << "Yes\n";
			}
		}
	}
}
int main() {
	solve();
	return 0;
}