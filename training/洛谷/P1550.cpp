#include <bits/stdc++.h>
#define int long long
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

const int N = 310;
int w[N], n, m; 
int p[N], g[N][N];
int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

vector<array<int, 3>> eg;
void solve(int CaseT) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		eg.pb({w[i], i, n + 1});
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j]; 
		}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			eg.pb({g[i][j], i, j});
	
	sort(all(eg));
	for (int i = 1; i <= n + 1; i++)
		p[i] = i;
	
	int ans = 0;
	
	for (auto [w, x, y] : eg) {
		int px = find(x);
		int py = find(y);
		if (px!=py) {
			p[px] = py;
			ans += w;
		}
	}
	cout << ans << '\n';
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _=1;
//  cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
