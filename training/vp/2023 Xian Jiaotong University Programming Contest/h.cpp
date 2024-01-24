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
typedef double db;
// head
int cnt[1010][26], n;
void solve(int CaseT) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (auto x : s) {
			cnt[i][x - 'a']++;
		}
	}
	int f = 0;
	map<int, int> ch;
	for (int i = 0; i < 26; i++) {
		map<int, int> mp;
		for (int j = 1; j <= n; j++) {
				mp[cnt[j][i]]++;
				if (cnt[j][i] != 0) ch[i]++;
		}
		if (SZ(mp) == n) {
			f = i + 1;
		}
	}
	
	if (f) {
		cout << "YES\n";
		string ans = "";
		for (int i = 0; i < 26; i++) {
			if (ch.count(i) != 0 && i != (f-1))
				ans.pb(char(i + 'a'));
		}
		ans.pb(char(f-1+'a'));
		cout << ans << '\n';
	} else {
		cout << "NO\n"; 
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
//	cin>>_;
	for (int i = 1; i <= _; i++)
		solve(i);
	return 0;
}
