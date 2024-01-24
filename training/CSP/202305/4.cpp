#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define lp (p << 1)
#define rp (p << 1 | 1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;
// -- head--
const int N = 10010;
int n, m, k;
vector<int> grp[N];
int g[N][N];
bool is[N];

struct node {
	int x, y, d;
	bool operator < (const node& R) const {
		return d < R.d;
	}
};

vector<node> edge;
int p[N];
int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}
int dis=0, res=1e9;
void krs() {
	sort(all(edge));
	for (int i = 0; i < n; i++) p[i] = i;
	for (auto x : edge) {
		int u = x.x, v = x.y, d = x.d;
		cout << u << " " << v << " " << d << '\n';
 		int pu = find(u), pv = find(v);
		if (pu != pv) {
			p[pu] = pv;
			dis += d;
			is[u] = is[v] = 1;
		} else {
			res = min(res, d);
		}
	}
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> k;
  
  for (int i = 0; i < n; i++) {
  	for (int j = 0; j < k; j++) {
  		cin >> g[i][j];
		}
	}
	
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		for (int j = 0; j < k; j++)
			for (int t = 0; t < k; t++) {
				int x; cin >> x;
				if (x == 0) {
					cout << u << " " << v << '\n'; 
				}
				edge.pb(node{u, v, x});
			}
	}
	
	krs();
	
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (is[i]) cur += 
	}
	
	if (m == n - 1) {
		cout << dis << '\n';
		return 0;
	}
	
	if (m == n) {
		cout << dis + res << '\n';
		return 0;
 	}
 	
 	cout << dis << '\n';
	
  return 0;
}
