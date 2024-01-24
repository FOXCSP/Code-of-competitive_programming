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
int a[200]; 
void solve(int CaseT) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		a[i] = 7;
	int ok = 0;
	for (int i = 1; i <= n * 3 - 3; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (!ok) {
			a[u] -= 1 << (v - 1);
			if (a[u] == 0 || a[u] == 4 || a[u] == 1) {
				if (i&1) ok = 2;
				else ok = 1;
			}
		}
	}
	cout << (ok == 2 ? "Nocriz\n" : "Sheauhaw\n");
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
