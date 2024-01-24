#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> vs;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		vs.pb(s);
	} 
	auto ck = [&](int i, int j, int p, int q) {
		bool f = 0;
		for (int t = 0; t < n; t++) if (vs[t][i] == 'v') {
			f = 1;
			break;
		}
		if (!f) return false;
		f = 0;
		for (int t = 0; t < n; t++) if (vs[t][j] == 'i') {
			f = 1;
			break;
		}
		if (!f) return false;
		f = 0;
		for (int t = 0; t < n; t++) if (vs[t][p] == 'k') {
			f = 1;
			break;
		}
		if (!f) return false;
		f = 0;
		for (int t = 0; t < n; t++) if (vs[t][q] == 'a') {
			f = 1;
			break;
		}
		if (!f) return false;
		return true;
	};
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			for (int p = j + 1; p < m; p++)
				for (int q = p + 1; q < m; q++) {
					if (ck(i, j, p, q)) {
						cout << "YES\n";
						return ;
					}
				}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _ = 1;
	cin >> _;
	for (; _--; ) {
		solve();
	}
		
	return 0;
} 
