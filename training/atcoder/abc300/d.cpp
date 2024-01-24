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

const int N = 110;

ll prime[300010], cnt;
ll pw[300010];
bool vis[300010];

void solve(int CaseT) {
	ll ans = 0;
	ll n;
	cin >> n;
	for (int i = 1; i <= cnt; i++)
		for (int j = i + 1; j <= cnt; j++) {
			ll a = pw[i];
			ll b = prime[j];
			ll c = n/(a*b);
			if (sqrtl(c) < b) break;
			int p = lower_bound(pw + 1, pw + cnt, c) - pw;
			if (pw[p] > c) p--;
			ans += p - j;
		}
	cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i < 300010; i++) {
		if (!vis[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] < 300010; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) 
				break; 
		} 
	}
	for (int i = 1; i <= cnt; i++) {
		pw[i] = prime[i] * prime[i]; 
	}
	int _;
  _=1;
//   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}

