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
	string s, p;
	cin >> s >> p;
	int n = SZ(s), m = SZ(p);
	s = "#" + s;
	p = "#" + p;
	vec<int> nxt(m + 1, 0);
	nxt[1] = 0;
	for (int i = 2, j = 0; i <= m; i++) {
		while (j && p[i] != p[j + 1]) 
			j = nxt[j];
		if (p[j + 1] == p[i])
			j++;
		nxt[i] = j;
	}
	vec<int> pos;
	for (int i = 1, j = 0; i <= n; i++) {
		while (j == m || (j && s[i] != p[j + 1]))
			j = nxt[j];
		if (p[j + 1] == s[i])
			j++;		
		if (j == m) {
			pos.pb(i - m + 1);
			j = nxt[j];
		}
	}
	if (SZ(pos))  {
		cout << SZ(pos) << '\n';
		for (auto x : pos) {
			cout << x << " "; 
		}
		cout << '\n';
	} else {
		cout << "-1\n";
		cout << "-1\n";
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
