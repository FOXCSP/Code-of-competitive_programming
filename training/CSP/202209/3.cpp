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
typedef pair<int, int> pii;
// head

map<int, int> lastday;
map<int, vector<pii>> dayrisk;
vector<int> risk, safe;
vector<array<int, 3>> evt;
int n, m;

void add(int d, int u, int r) {
	risk.pb(u);
	auto x = dayrisk[r]; 
		for (auto y : x) {
			if (y.fi <= d && y.se >= d) 
				lastday[u] = y.se;
				return ;
 		} 
} 

bool isrisk(int d, int u, int r) {
	if (dayrisk.count(r) != 0) {
		auto y = dayrisk[r];
		for (auto x : y) {
			if (x.fi <= d && d <= x.se) {
				risk.pb(u);
				auto &pp = lastday[u];
				pp = max(pp, d + 6);
//				pp = min(pp, d + 6);
				return true;
			}
		}
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int ri, m;
		cin >> ri >> m;
		for (int j = 1; j <= ri; j++) {
			int p;
			cin >> p;
			if (dayrisk.count(p) != 0) {
				auto &xx = dayrisk[p];
				if (xx.back().se >= i) {
					xx.back().se = max(xx.back().se, i + 6);
				}
				else  {
					xx.pb({i, i + 6});
				}
			} else {
				dayrisk[p].pb({i, i + 6});
			}
 		}
 		
 		
 		vector<array<int, 3>> newevt;
 		
 		for (auto x : evt) {
 			int d = x[0], u = x[1], r = x[2];
 			if (i - 6 > d) continue;
 			if (isrisk(d, u, r)) {
			
		 	} else {
		 		newevt.pb({d, u, r}); 
		 	}
		}
 		
 		
		for (int j = 1; j <= m; j++) {
			int d, u, r;
			cin >> d >> u >> r;
			if (i - 6 > d) continue;
			if (isrisk(d, u, r)) {
				
			} else {
				newevt.pb({d, u, r});	
			}
		} 
		
		evt.swap(newevt);
		
		sort(all(risk));
		risk.erase(unique(all(risk)), risk.end());
		vector<int> newrisk;
		for (auto x : risk) {
			 if (lastday[x] >= i)
			 	newrisk.pb(x);
		}
		risk.swap(newrisk);
		cout << i << " ";
		for (auto x : risk) cout << x << " ";
		cout << '\n';
		
//		cout << i << " ---\n"; 
//		for (auto x : dayrisk) {
//			cout << x.fi << ":\n";
//			for (auto y : x.se) {
//				cout << y.fi << " " << y.se << '\n';
//			}
//		}
		
		
	}
	
	return 0;
} 
