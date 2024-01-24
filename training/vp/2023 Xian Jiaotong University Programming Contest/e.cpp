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
typedef double db;
// head
const int N = 210;
int n;
double g[N][N], b;
int dg[N];
void solve(int CaseT) {
	cin >> n >> b;
	for (int i = 1; i <= n; i++) dg[i] = 0;
	vector<pair<db, int>> pos[N];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
			if (i != j && g[i][j] >= b) 
				pos[i].pb({g[i][j], j});
		}
		if (SZ(pos[i])) {
			sort(all(pos[i]));
			dg[pos[i].back().se]++;
//			cout << pos[i].back().se << '\n';
		}
	}
	if (n == 1) {
		cout << "kono jinsei, imi ga nai!\n";
		return ;
	}
	bool ok = 1;
	for (int i = 1; i <= n; i++) {
		if (dg[i] == 0)
			ok = false;
	}
	if (!ok) cout << "hbxql\n";
	else cout << "wish you the best in your search\n";
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
