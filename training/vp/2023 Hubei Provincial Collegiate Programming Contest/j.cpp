#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef long double lbd;
typedef double db;
// head

const int N = 1000010, mod = 998244353;
int a[N];
int pre[N];
void solve(int CaseT) {
	int n;
	cin >> n;
	int fir = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if(i == 0) {
			fir = a[0];
		} else {
			pre[i] = pre[i - 1] + a[i];
		}
	}
	pre[0] = fir;
	pre[n] = INF;
	
	if (a[0] < 0 || pre[n] < 0) {
		cout <<-1<<"\n";
		return;
	}
	int l = 0;
	int tmp = 0;
	int minn = INF;
	ll t = 0;
	ll now = 0;
	int z;
	for (int r = 0; r <= n; r++) {
		if (pre[r] > pre[l]) {
			// jump
			tmp = 0;
			minn = INF;
			for (int i = l+1; i < r; i++) {
				tmp += pre[i];
				minn = min(minn, tmp);
			}
			minn = abs(minn);
			if (now > minn) {
				now -= minn;
			} else {
				z = ceil(1.0 * (minn - now) / pre[l]);
				t += r - l + 1 - z;
				now += z * pre[l] - minn;
			}
			l = r;
		}
	}
	cout << t<<endl;
	
}

signed main() {
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
/*
6 1
5 5 8 9 9 8 
*/
