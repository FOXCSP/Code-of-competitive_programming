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
// Z algorithm 最长公共前后缀 
// Z[i] 表示字符串S和S[i]...S[n]的最长公共前缀

vector<int> Z_algorithm(string s) {
	int n = SZ(s);
	vec<int> Z(n + 1, 0);
	Z[1] = 0;
	int l = 1, r = 0;
	for (int i = 2; i < n; i++) {
		if (i > r) {
			Z[i] = 0;
		} else {
			int k = i - l + 1;
			Z[i] = min(Z[k], r - i + 1);
		}
		
		while (i + Z[i] <= n && s[Z[i] + 1] == s[Z[i] + i]) Z[i]++;
		if (i + Z[i] - 1 > r)
			l = i, r = i + Z[i] - 1;
	}
	return Z;
}

void solve(int CaseT) {
	string s, p;
	cin >> s >> p;
	int n = SZ(s), m = SZ(p);
	string res = "#" + p + "#" + s;
	auto Z = Z_algorithm(res);
	
	vec<int> pos;
	for (int i = m + 1; i < SZ(res); i++) {
		if (Z[i] == m) {
			pos.pb(i - m - 1);
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
