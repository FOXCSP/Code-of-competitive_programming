#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int n, m;
set<string> p;
vector<string> s;
bool st[10];
void dfs(int u, string nstr, int rest) {
	if(n == u) {
		auto sz = nstr.size();
		if(sz < 3 || sz > 16) return ;
		if(!p.count(nstr)) {
			cout << nstr << '\n';
			exit(0);
			return ;
		}

	} else {
		for(int i = 0; i < n; i ++)
			if(!st[i]) {
				st[i] = 1;
				string pstr = nstr;
				pstr += s[i];
				if(u == n - 1) dfs(u + 1, pstr, rest);
				else {
					for(int _ = 1; _ <= rest ; _ ++)
						if(_ + n - 2 - u <= rest) {
							pstr.push_back('_');
							dfs(u + 1, pstr, rest - _);
						}
				}
				st[i] = 0;
			}
	}
}

void solve () {
	cin >> n >> m;
	int sz = 0;
	for(int i = 1; i <= n; i ++) {
		string x;
		cin >> x;
		s.push_back(x);
		sz += x.size();
	}
	for(int i = 1;i <= m; i ++) {
		string x;
		cin >> x;
		p.insert(x);
	}
	dfs(0, "", 16 - sz);
	cout << "-1\n";
}


int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}