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

vector<int> init(string s) {
	vec<int> nxt(SZ(s) + 1, 0);
	nxt[1] = 0;
	int n = SZ(s) - 1;
	for (int i = 2, j = 0; i <= n; i++) {
		while (j && s[i] != s[j + 1]) 
			j = nxt[j];
		if (s[i] == s[j + 1])
			j++;
		nxt[i] = j;
	}
	return nxt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
	string s;
//	int id = 3;
	while (cin >> s) {
		if (s == ".") break;
		int n = SZ(s);
		s = "#" + s;
		auto nxt = init(s);	
		int res = n - nxt[n];
		if (n % res == 0) {
			cout << n / res << '\n';
		} else {
			cout << 1 << '\n';
		}
	}
  return 0;
}
