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
	s = "#" + s;
	auto init = [&] (string s){
		vec<int> nxt(SZ(s) + 1, 0);
		nxt[1] = 0;
		for (int i = 2, j = 0; i <= n; i++) {
			while (j && s[i] != s[j + 1]) 
				j = nxt[j];
			if (s[i] == s[j + 1])
				j++;
			nxt[i] = j;
		}
		return nxt;
	};
	auto nxt = init(s);
	cout << n - nxt[n] << '\n';
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
