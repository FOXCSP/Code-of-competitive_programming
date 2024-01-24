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

vector<int> manacher(string s) {
	int n = SZ(s), m = 0; // 1 base
	string t = "$";
	for (int i = 0; i < n; i++) {
		t.pb(s[i]);
		t.pb('$'); 
	}
	
	m = SZ(t);
	vec<int> p(m + 1, 0); 

	int M = 0, R = 0;
	for (int i = 1; i <= m; i++) {
		if (i > R) {
			p[i] = 1;
		} else {
			p[i] = min(p[2 * M - i], R - i + 1);
		}
		while (p[i] + i <= m && i - p[i] >= 0 && t[i + p[i]] == t[i - p[i]])
			++p[i];
		if (i + p[i] - 1 > R)
			M = i, R = i + p[i] - 1;
	}
	return p;
}

void solve(int CaseT) {
	string s;
	cin >> s;
	auto p = manacher(s);
	int ans = 0; 
	for (int i = 1; i < SZ(p); i++)
		ans = max(ans, p[i]);
	cout << ans - 1 << '\n';
}	

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;
//   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
