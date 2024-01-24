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
const int N = 1000010;
vector<int> exkmp(string s) {
	int n = SZ(s);
	vec<int> z(n + 1, 0);
	z[1] = 0;
	int L = 1, R = 0;
	for (int i = 2; i < n; i++) {
		if (i > R) z[i] = 0;
		else {
			int k = i - L + 1;
			z[i] = min(z[k], R - i + 1);
		}
		while (i + z[i] < n && s[z[i] + 1] == s[z[i] + i]) ++z[i];
		if (R < i + z[i] - 1) {
			L = i, R = i + z[i] - 1;
		}
	}
	return z;
}

void solve(int CaseT) {
	string s;
	cin >> s;
	int n = SZ(s);
	s = "#" + s;
	auto z = exkmp(s);
	int mx = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i + z[i] - 1 == n)
			if (mx >= z[i])
				ans = max(ans, z[i]);
			mx = max(mx, z[i]);	
	}
	
	if (ans == 0) {
		cout << "Just a legend\n";
	} else {
		for (int i = 1; i <= ans; i++)
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
