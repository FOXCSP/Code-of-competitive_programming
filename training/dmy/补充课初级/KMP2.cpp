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

vector<int> init(string s) {
	vec<int> nxt(SZ(s) + 1, 0);
	nxt[1] = 0;
	int n = SZ(s);
	for (int i = 2, j = 0; i <= n; i++) {
		while (j && s[i] != s[j + 1])
			j = nxt[j];
		if (s[i] == s[j + 1])
			j++;
		nxt[i] = j;
	}
	return nxt;
}

void solve(int CaseT) {
	string s, p;
	cin >> s >> p;
	int n = SZ(s), m = SZ(p);
	string T = "#" + p + "#" + s;
	auto nxt = init(T);
	vec<int> pos; 
	for (int i = m; i < SZ(T); i++) {
		if (nxt[i] == m) {
			pos.pb(i - 2 * m);
		}
	}
	if (SZ(pos)) {
		cout << SZ(pos) << '\n';
		for (auto x : pos) {
			cout << x << " ";
		} 
		cout << '\n';
	} else {
		cout << "-1\n-1\n";
	}
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
