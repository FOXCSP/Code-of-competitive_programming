#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;
map<int,vector<int>> PA, JD;
map<int, set<int>> PB;
map<pair<int, int>, int> YY;
int info[1001];
int n, m; 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		JD[x].pb(i);
	}
	auto &rrrr = JD[0];
	for (int i = 1; i <= n; i++) 
		rrrr.pb(i);
	for (int i = 1; i <= n; i++) info[i] = 0;
	int _; cin >> _;
	for (int __ = 1; __ <= _; __++) {
		int f, a, na, pa, paa, paar;
		cin >> f >> a >> na >> pa >> paa >> paar;
		for (int j = 1; j <= f; j++) {
			// 取出 分区na的节点，如果 na=0, 那么为全部节点 
			vector<int> JieDian = JD[na]; 
			if (SZ(JieDian) == 0) {
				cout << 0 << " ";
				continue;
			}
			if (pa) {
				vector<int> New;
				auto it = PB[pa].begin(), it2 = PB[pa].end();
				for (it; it != it2; it++) {
					for (auto z : PA[*it]) {
						New.pb(z);
					}
				}
				JieDian = New;
			}
			
			vector<int> New; 
			if (paa) {
				map<int, int> mp;
				for (auto x : PA[paa]) mp[x]++;
				for (auto x : JieDian) {
					if (mp.count(x) == 0)
						New.pb(x);
				}
			}
			if (paar == 1 && SZ(New) == 0) {
				cout << 0 << " ";
				continue; 
			}
			if (SZ(New)) JieDian = New; 
			sort(all(JieDian), [&](int x, int y) {
				if (info[x] != info[y]) return info[x] < info[y];
				else return x < y;
			});
			PB[a].insert(na); 
			PA[a].pb(JieDian[0]);
			info[JieDian[0]]++;
			cout << JieDian[0] << " ";
		}
		cout << '\n'; 
	}
	return 0; 
}
