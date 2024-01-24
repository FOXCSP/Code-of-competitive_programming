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
	string s;
	cin >> s;
	string t = s;
	int n = SZ(s);
	reverse(all(t));
	s = "#" + s + "#" + t;
	
	auto init = [&](string s) {
		int m = SZ(s);
		vec<int> nxt(m + 1, 0);
		nxt[1] = 0;
		for (int i = 2, j = 0; i < m; i++) {
			while (j && s[i] != s[j + 1])
				j = nxt[j];
			if (s[i] == s[j + 1])
				j++;
			nxt[i] = j;
		}
		return nxt;
	};
	auto nxt = init(s);
	int mx = 0;
	for (int i = n + 1; i < SZ(s); i++)
		mx = max(mx, nxt[i]);
//	cout << mx << '\n';
	for (int i = mx; i >= 1; i--) {
		cout << s[i];
	}
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
