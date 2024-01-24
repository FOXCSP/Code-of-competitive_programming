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

int n, k;
int prime[10000010];
void solve(int CaseT) {
	cin >> n;
	vec<int> pr;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 2; j <= x / j; j++) {
			if (x % j == 0)
				pr.pb(j);
			while (x % j == 0) {
				x /= j;
				prime[j]++;
			}
		}
		if (x > 1)
			prime[x]++, pr.pb(x);
	}
	int ans = 0, res = 0;
	sort(all(pr));
	pr.erase(unique(all(pr)), pr.end());
	for (auto x : pr) {
//		cout << x << " " << prime[x] << '\n';
		ans += prime[x] / 2;
		res += prime[x] % 2; 
	}
	ans += (res/3);
	cout << ans << '\n';
	for (auto x : pr) {
		prime[x]=0;
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;
   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
