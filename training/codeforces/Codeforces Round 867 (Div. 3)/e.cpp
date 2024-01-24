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
	int n;
	string s;
	cin >> n >> s;
	if (n & 1) {
		cout << "-1\n";
		return ;
	}
	vec<int> ch(26, 0), ct(26, 0);
	
	for (int i = 0; i < n; i++)
		ct[s[i] - 'a']++;
	
	for (int i = 0; i < n / 2; i++) {
		if (s[i] == s[n - 1 - i]) {
			ch[s[i] - 'a']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (ct[i] > n / 2) {
			cout << "-1\n";
			return ;
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans += ch[i];
		if (ans > n / 2) {
			cout << "-1\n";
			return ;
		}
	}
	ans = (ans + 1) / 2;
	for (int i = 0; i < 26; i++) {
		ans = max(ans, ch[i]);
	}
	cout << ans << '\n';
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
10
ababbbbaaa

ababbbbaaa


*/
