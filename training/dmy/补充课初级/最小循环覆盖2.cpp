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

string getMin(string s) {
	int n = SZ(s);
	s = "#" + s + s;
	int i = 1, j = 2;
	while (j <= n) {
		int k = 0;
		while (k < n && s[i + k] == s[j + k])
			++k;
		if (s[i + k] > s[j + k])
			i += k + 1;
		else 
			j += k + 1;
		
		if (i == j)
			++j;
		
		if (i > j)
			swap(i, j); 
	}
	string res = "";
	for (int l = i; l <= i + n - 1; l++)
		res.pb(s[l]);
	return res;
}

vec<int> kmp_init(string s) {
	int n = SZ(s);
	s = "#" + s;
	vec<int> nxt(n + 1, 0);
	nxt[1] = 0;
	for (int i = 2, j = 0; i <= n; i++) {
		while (j && s[i] != s[j + 1]) j = nxt[j];
		if (s[i] == s[j + 1])
			j++;
		nxt[i] = j;
	}
	return nxt;
}

void solve(int CaseT) {
	string s;
	cin >> s;
	auto nxt = kmp_init(s);
	int n = SZ(s) - nxt[SZ(s)];
	string t = "";
	for (int i = 0; i < n; i++)
		t.pb(s[i]);
//	cout << t << '\n';
	auto res = getMin(t);
	cout << res << '\n';
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
