#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

const int N = 200010;
int r[N];
int cnt[N] ,vis[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
		vis[r[i]]++;
	} 
	
	for (int i = 1; i <= n; i++) {
		int x = r[i];
		for (int j = 1; j <= x / j; j++) {
			if (x % j == 0) {
				if (j == 1) {
					if (vis[1] && x != 1)
						cnt[x]++;
					if (vis[x] > 1)
						cnt[1]++;
				} else {
					if (vis[j])
						cnt[x / j]++;
					if (vis[x / j])
						cnt[j]++;
				}
			}
		}
	}
	
	for (; q--; ) {
		int x;
		cin >> x;
		if (cnt[x]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	} 
	return 0;
} 
