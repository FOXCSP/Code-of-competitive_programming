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

int n, k;
void solve(int CaseT) {
	cin >> n >> k;
	vec<int> pos[n + 1];
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		pos[i % k].pb(x);
	}
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		int p = i;
		if (!p) p = k;
		int res = 0;
		for (int j = 0; j < SZ(pos[i]); j++) {
			if ((pos[i][j] - p) % k != 0)
				cnt++, res++;
		}
		if (res > 1) {
			cout << "-1\n";
			return ; 
		}
	}
	 
	if (cnt > 2) {
		cout << "-1\n";
	} else {
		cout << cnt / 2 << '\n';
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
/*
1
5 4
5 4 2 3 1
*/
