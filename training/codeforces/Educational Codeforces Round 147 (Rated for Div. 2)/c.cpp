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

const int N = 200010;
void solve(int CaseT) {
	string s;
	cin >> s;
	vec<int> pos[26]; 
	for (int i = 0; i < SZ(s); i++) {
		pos[s[i] - 'a'].pb(i + 1);
	}
	int ans = 1<<30;
	for (int i = 0; i < 26; i++) {
		if (SZ(pos[i]) == 0)
			continue;
		int res = 0;
		int pre = 0;
		for (int j = 0; j < SZ(pos[i]); j++) {
			if (pos[i][j] > 1) res = max(res, pos[i][j] - pre - 1);
			pre = pos[i][j];
		}
		res = max(res, SZ(s) - pre);
		ans = min(ans, res);
	} 
	int x = 0;
//	cout << ans << " xx\n";
	while (ans) {
		ans/=2;
		x++;
	}
	cout << x << '\n';
	for (int i = 0; i < 26; i++)
		pos[i].clear(); 
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
