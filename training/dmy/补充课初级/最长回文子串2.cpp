#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
#define P(T) pair<T, T>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
// head
const db EPS = 1e-6;
const int N = 100010, M = 200010, inf = 1001;
int n, m;
int a[N], b[M];

const ll mod1 = 998244353, mod2 = 1000000007;
const ll base1 = 1331, base2 = 2333;
ll pw1[M], pw2[M];
ll c1[M], r1[M], c2[M], r2[M];
ll len[M], ans = -(1<<30);

P(ll) get_hs1(int l, int r) {
	return P(ll) {
		(c1[r] - c1[l - 1] * pw1[r - l + 1] % mod1 + mod1) % mod1, 
		(c2[r] - c2[l - 1] * pw2[r - l + 1] % mod2 + mod2) % mod2
	};
}

P(ll) get_hs2(int l, int r) {
	return P(ll) {
		(r1[l] - r1[r + 1] * pw1[r - l + 1] % mod1 + mod1) % mod1,
		(r2[l] - r2[r + 1] * pw2[r - l + 1] % mod2 + mod2) % mod2
	};
}

void solve(int CaseT) {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	b[0] = inf;
	for (int i = 1; i <= n; i++)
		b[++m] = a[i], b[++m] = inf;
	
//	for (int i = 0; i <= m; i++)
//		cerr << b[i] << " \n"[i ==m];
	
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i <= m; i++)
		pw1[i] = (pw1[i - 1] * base1) % mod1,
		pw2[i] = (pw2[i - 1] * base2) % mod2;
		
	for (int i = 1; i <= m; i++)
		c1[i] = (c1[i - 1] * base1 % mod1 + b[i]) % mod1,
		c2[i] = (c2[i - 1] * base2 % mod2 + b[i]) % mod2;
	
	for (int i = m - 1; i >= 1; i--)
		r1[i] = (r1[i + 1] * base1 % mod1 + b[i]) % mod1,
		r2[i] = (r2[i + 1] * base2 % mod2 + b[i]) % mod2; 
	
	for (int i = 1; i <= m; i++) {
		int l = 0, r = min(i, m - i + 1) + 1;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (get_hs1(i - mid + 1, i) == get_hs2(i, i + mid - 1)) 
				l = mid;
			else
				r = mid - 1;
		}
		len[i] = l - 1;
//		cout << i << " " << l << " " << len[i] << '\n'; 
		ans = max(ans, len[i]);
	}
	cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;
//   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
