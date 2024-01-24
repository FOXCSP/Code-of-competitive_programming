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
int id = 0;
int n, m, q;
map<string, int> idx;
map<int, vector<string>> type, source, opt;
map<int, vector<pair<string, string>>> rel; // 关系 
int p[200010];
int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

int get(string s) {
	if (idx.count(s) == 0) {
		idx[s] = ++id;
		type[id].clear();
		source[id].clear();
		opt[id].clear(); 
	}
	return idx[s];
}

void add(vector<string> &a, vector<string> &b) {
	for (auto x : b) {
		a.pb(x);
	}
	sort(all(a));
	a.erase(unique(all(a)), a.end());
}

void ADD(vector<pair<string, string>> &a, vector<pair<string, string>> &b) {
	for (auto x : b) {
		a.pb(x);
	}
	sort(all(a));
	a.erase(unique(all(a)), a.end());
}

void merge(int x, int y) {
	int px = find(x), py = find(y);
	if (px != py) {
		p[py] = px;
		add(opt[px], opt[py]);
		add(type[px], type[py]);
		add(source[px], source[py]);
		ADD(rel[px], rel[py]);
	}
}

 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i = 0; i <= 200000; i++) p[i] = i;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		string name;
		int nv, no, nn;
		cin >> name;
		int ID = find(get(name));
		auto &x = opt[ID]; // 集合的 指令集
		auto &y = type[ID];
		auto &z = source[ID];
		cin >> nv;
		vector<string> x1, x2, x3;
		for (int _ = 1; _ <= nv; _++) {
			string op;  cin >> op;
			x.pb(op);
		} 
		cin >> no;
		for (int _ = 1; _ <= no; _++) {
			string op; cin >> op;
			y.pb(op);
		}
		cin >> nn;
		if (nn == 0) {
			z.pb("*"); 
		}
		for (int _ = 1; _ <= nn; _++) {
			string op; cin >> op;
			z.pb(op);
		}
	}
	
	
	for (int i = 1; i <= m; i++) {
		string usr; 
		int ns; 
		cin >> usr >> ns;
		for (int j = 1; j <= ns; j++) {
			string a, b;
			cin >> a >> b;
			if (a == "u") {
				merge(get(usr), get(b));
			} else {
				merge(get(usr), get(b));
			}
		}
	}
	
	for (int _ = 1; _ <= q; _++) {
		string usr;
		int ng;
		cin >> usr >> ng;
		int ID = find(get(usr));
		vector<string> oo = opt[ID], tt = type[ID], ss = source[ID];
		vector<pair<string, string>> rr = rel[ID];
		for (int i = 1; i <= ng; i++) {
			string s;
			cin >> s;
			int ps = find(get(s));
			auto &x = opt[ps];
			for (auto v : x) {
				oo.pb(v);
			}
			auto &y = type[ps];
			for (auto v : y) {
				tt.pb(v);
			}
			auto &z = source[ps];
			for (auto v : z) {
				ss.pb(v);
			}
//			auto &t = rel[ps];
//			for (auto v : t) {
//				rr.pb(v);
//			}
		}
		
		bool f = 0;
		string op1, op2, op3;
		cin >> op1 >> op2 >> op3;
		
//		for (auto x : rr) {
//			if (pair<string, string>{op1, op2} == x) {
//				f = 1;
//				break;
//			}
//		}
//		
//		if (f) {
//			cout << "1\n";
//			continue;
//		}
		
		
		for (auto x : oo) {
			if (x == "*" || x == op1) {
				f = 1;
				break;
			}
		}
		
		if (!f) {
			cout << "0\n"; //找不到指令 
			continue;
		}
		
		f = 0;
		for (auto x : tt) {
			if (x == "*" || x == op2) {
				f = 1;
				break;
			}
		} 
		
		if (!f) {
			cout << "0\n"; // 找不到该种类
			continue; 
		}
		
		f = 0;
		for (auto x : ss) {
			if (x == "*" || x == op3) {
				f = 1;
				break;
			}
		}
	
		if (!f) cout << "0\n";
		else cout << "1\n";
	}
	
	
	return 0;
} 
