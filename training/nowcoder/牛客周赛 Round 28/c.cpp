#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define all(T) T.begin(), T.end() 
#define SZ(T) (int(T.size()))
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

void solve(int CaseT = 1) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(m + 1, n);
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    if (x >= n - a[y] + 1) a[y]--;
  }
  vector<int> b(m + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (b[j] + a[j] < n) {
        cout << ".";
        b[j]++;
      } else cout << "*";
    }
    cout << '\n';
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_ = 1;
//	cin >> _;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
} 
