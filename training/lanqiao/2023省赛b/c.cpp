#include <bits/stdc++.h>
#define vec vector
#define se second
#define fi first
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;

const int N = 10010;
int a[N], b[N], n;

void solve (int Case) {
	cin >> n;
	
	int mx=1e9, mn=-1e9;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
//		cout << a[i] / b[i] << '\n';
		mx = min(mx, a[i]/b[i]);
		mn = max(mn, a[i]/(b[i]+1)+1);
//		cout << i << " " << a[i]/b[i] << " " << (a[i]/(b[i]+1)+1) << '\n';
	}

	cout << mn << " " << mx <<'\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
	for (int i=1; i<=_;i++) {
		solve(i);
	}
	return 0;
}
