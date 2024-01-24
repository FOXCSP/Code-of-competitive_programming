#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;

int R;
int get(int l, int r) {
	int x=l/R, y=r/R;
	int len=r-l+1;
	int l1=(R-(l%R));
	int l2=((r%R)+1); 
	len-=l1;
	if (len==0) return l1*x;
	len-=l2;
	if (len==0) return l1*x+l2*y;
	return l1*x+l2*y+(len/R)*(x+y)/2*R;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	R = m / (n + 1);
	vector<int> a(n + 2, 0);
	a[n + 1] = m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int s1 = i * (a[i + 1] - a[i]);
		int s2 = get(a[i], a[i + 1] - 1);
		int l = a[i] - 1, r = a[i + 1] - 1;
		while (l < r) {
			int M = (l + r + 1) / 2;
			if (M / R < i) l = M;
			else r = M - 1;
		}
		ans += (s2 - s1 + 2 * ((l - a[i] + 1) * i - get(a[i], l)));
	}
	cout << ans << '\n';
	return 0; 
} 
