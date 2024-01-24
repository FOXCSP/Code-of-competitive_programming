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

const int N = 100010, inf = 1 << 30;
int a[N], n, f[N], len; 
void solve(int CaseT) {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	f[0] = -1e9, len = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0, r = len;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (f[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		f[r + 1] = a[i];
		if (l >= len) len++; 
//		cout << " now in f: " << len << " ";
//		for (int i = 1; i <= len; i++)
//			cout << f[i] << " \n"[i == len];
	}
//	for (int i = 1; i <= len; i++) {
//		cout << f[i] << " \n"[i == len];
//	}
	cout << len <<'\n';
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
