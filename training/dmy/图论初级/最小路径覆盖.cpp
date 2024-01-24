#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define setdb cout<<fixed<<setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--
const int N = 1010, M = N * 2;
int n, m;
vec<int> e[M];
bool vis[M];
int par[M];

bool find(int x) {
	vis[x] = 1;
	for (auto y : e[x]) {
		if ((!par[y]) || (!vis[par[y]] && find(par[y]))) {
			par[y] = x;
			return true;
		}
	}
	return false;
}

void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
    	int x, y;
    	cin >> x >> y;
    	e[x].pb(y + n);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
    	memset(vis, false, sizeof vis);
    	if (find(i))
    		ans++;
    }
    cout << n - ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    _ = 1;
    // cin >> _;
    for (int i = 1; i <= _; i++) {
        solve(i);
    }
    return 0;
}