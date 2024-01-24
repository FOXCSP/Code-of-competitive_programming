#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
#define P(T) pair<T, T>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
// head

const int N = 200010;
int n, k;
int x[N], c[N];

int calc(string s) {
	int m = SZ(s);
	map<string, int> mp;
	auto ok = [&](int p, int q) {
		int a = p, b = q;
		while (p < q && s[p] == s[q])
			p++, q--;
		if (p < q) return false;
		return true;
	};
	
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			if (ok(i, j)) {
				mp[s.substr(i, j - i + 1)]++;
			}
		}
	}
	return SZ(mp);
}

void solve(int CaseT) {
	cin >> n >> k;
	
	for (int i = 1; i <= k; i++)
		cin >> x[i];
	
	for (int i = 1; i <= k; i++)
		cin >> c[i];
	
	string ans = "abc";
	
	for (int i = 1; i <= k; i++) {
		int m = x[i] - x[i - 1];
		int d = c[i] - c[i - 1];
		if (i == 1)
			d -= 3;
		
		while (SZ(ans) < x[i] && d) {
			ans.pb(ans.back()), d--;
		}
		
		if (SZ(ans) == x[i] && d) {
			cout << "NO\n";
			return ;
		}
		
		while (d == 0 && SZ(ans) < x[i]) {
			if (SZ(ans) < x[i] && ans.back() != 'a') ans.pb('a');
			if (SZ(ans) < x[i] && ans.back() != 'b') ans.pb('b'); 
			if (SZ(ans) < x[i] && ans.back() != 'c') ans.pb('c');
		}
	}
	cout << "YES\n";
//	cout << ans << '\n';
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

/*
1
10 2
5 10
5 6

*/
