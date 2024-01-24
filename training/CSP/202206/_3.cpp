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
struct name {
	map<string, bool> opt, type, source;
};
map<string, name> mp;
map<string, vector<string>> usr, grp;
int n, m, q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		name a;
		string Name;
		int nv, no, nn;
		cin >> Name;
		cin >> nv;
		for (int j = 1; j <= nv; j++) {
			string op; cin >> op;
			a.opt[op] = 1;
		}
		cin >> no;
		for (int j = 1; j <= no; j++) {
			string ty; cin >> ty;
			a.type[ty] = 1;
		}
		cin >> nn;
		if (nn == 0) a.source["*"] = 1;
		for (int j = 1; j <= nn; j++) {
			string ss; cin >> ss;
			a.source[ss] = 1;
		}
		mp[Name] = a;
	}
	for (int i = 1; i <= m; i++) {
		string Name;
		int ns;
		cin >> Name >> ns;
		for (int j = 1; j <= ns; j++) {
			string a, b;
			cin >> a >> b;
			if (a == "u") {
				usr[b].pb(Name);
			} else {
				grp[b].pb(Name);
			}
		}
	}
	for (int _ = 1; _ <= q; _++) {
		string Name, op, ty, sur;
		int ng;
		cin >> Name >> ng;
		vector<string> G;
		for (int i = 0; i < ng; i++) {
			string s;cin >> s;
			G.pb(s);
		} 
		cin >> op >> ty >> sur;
		bool f = 0;
		for (auto x : usr[Name]) {
			if (mp[x].opt.count("*") == 0 && mp[x].opt.count(op) == 0) continue;
			if (mp[x].type.count("*") == 0 && mp[x].type.count(ty) == 0) continue;
			if (mp[x].source.count("*") == 0 && mp[x].source.count(sur) == 0) continue;
			f = 1;
			break;
		}
		for (auto gg : G) {
			if (f) break;
			for (auto x : grp[gg]) {
    			if (mp[x].opt.count("*") == 0 && mp[x].opt.count(op) == 0) continue;
    			if (mp[x].type.count("*") == 0 && mp[x].type.count(ty) == 0) continue;
    			if (mp[x].source.count("*") == 0 && mp[x].source.count(sur) == 0) continue;
    			f = 1;
    			break;
			}
		}
		cout << (f ? "1" : "0") << '\n';
	}
	return 0;
} 
