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

void solve(int CaseT) {
	int n, m;
	cin >> n >> m;
	int cnt= 0;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (auto x : s) {
			if (x == '@')
				cnt++;
		}
	}
	cout << cnt / 2 << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _=1;
//  cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}