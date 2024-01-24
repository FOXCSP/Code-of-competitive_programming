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
// head
void solve(int CaseT) {
	int n;
	cin >> n;
	map<pair<int, int>, int> mp, hs;
	for (int  i= 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		mp[{x, y}]++;
 	}
 	
 	hs[{0, 0}]++;
 	if (mp.count({0, 0}) == 0) {
 		cout << "-1\n";
 		return ;
	}
	
	int ans = 0;
	int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	vector<pair<int, int>> now;
	now.pb({0, 0});
	while (1) {
		int p = 0;
		for (int i = 0; i < 4; i++) {
			vector<pair<int, int>> nxt;
			bool f = 1;
			
			for (auto [x, y] : now) {
				int nx = x + D[i][0], ny = y + D[i][1];
				if (mp.count({nx, ny}) == 0) {
					f = false;
					p++;
					break;
				}
				if (hs.count({nx, ny}) != 0) continue;
				nxt.pb({nx, ny});
			}
			
			if (f) {
				for (auto x : nxt) {
					hs[x]++;
					now.pb(x);
				}
				ans++;
			}
			
		}
//		cout << p << " " << ans << '\n'; 
		if (p == 4) {
			break;
		}
		if (SZ(hs) == SZ(mp)) {
			break;
		}
	}
	
	if (SZ(hs) != SZ(mp))
		ans = -1;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int _;
	_=1;
//	cin>>_;
	for (int i = 1; i <= _; i++)
		solve(i);
	return 0;
}

