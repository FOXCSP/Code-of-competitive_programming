#include <bits/stdc++.h>
#define int long long

using namespace std;
using PII = pair<int,int>;
using ll = long long;

const int N = 500010;

vector<vector<ll>> v, s;
int n, k, q;

map<pair<int,int>, int> mp;


ll ask(int l, int r) {
	int t = 0;
	for(int i = 1; i <= k; i ++) {
		int x = s[i][r] - s[i][l - 1];
		t = max(t, x);
	}
	return t;
}

void solve() {
	scanf("%lld%lld%lld", &n, &k, &q);
	v.resize(k+1);
	s.resize(k+1);
	for(int i = 1;i <= k; i ++) {
		v[i].resize(n+1);
		s[i].resize(n+1, 0);
		for(int j = 1; j <= n; j ++) {
			cin >> v[i][j];
			s[i][j] = s[i][j - 1] + v[i][j];
		}
	}

	while(q --) {
		int l, r; 
		scanf("%d %d", &l, &r);
		if(mp[{l, r}]) cout << mp[{l, r}] << '\n';
		else {
			int t = ask(l, r);
			mp[{l, r}] = t;
			printf("%lld\n", t);
		}
	}
}

signed main() {
	solve();
	return 0;
}