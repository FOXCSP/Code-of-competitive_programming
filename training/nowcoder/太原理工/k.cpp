#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define pb push_back
#define all(T) T.begin(), T.end()
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

const int N = 101010;
int n, m;

ldb f[129][129][8];
ldb a[129];
void solve(int CaseT = 1) {
	cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    int p = 0;
	while ((1 << p) != n) p++;
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		for (int k = 1; k <= p; k++) {
    			f[i][j][k] = f[j][i][k] = 1;
			}
		}
	}
    
	for (int i = 1; i <= n; i++) {
        if (i&1) {
            f[i][i+1][1] = a[i]/(a[i]+a[i+1]);
            f[i+1][i][1] = a[i+1]/(a[i]+a[i+1]);
        }
    }
    
    
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 2; k <= p; k++) {
                for (int t = 1; t <= n; t++) {
                    if (i != j && j != t && i != t) {
                        f[i][j][k] *= f[j][t][k - 1] * (a[i]/(a[i]+a[j]));
                    }
                }
            }
		}
	}
    cout << p << '\n';
	cout << fixed << setprecision(9);
    for (int i = 1; i <= n; i++) {
        ldb res = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            res += f[i][j][p];
        }
        cout << res << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_ = 1;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}
