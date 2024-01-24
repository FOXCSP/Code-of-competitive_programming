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

const int N = 10000;
int n, m;

ldb f[N];
ldb a[N];

int L[N << 8], R[N << 8];

void build(int p, int l, int r) {
	L[p] = l;
	R[p] = r;
	if (l == r) return ;
	else {
		int mid = (l + r) / 2;
		build(lp, l, mid);
		build(rp, mid + 1, r);
	}
}

void merge(int p) {
	int l1 = L[lp];
	int r1 = R[lp];
	int l2 = L[rp];
	int r2 = R[rp];
//     cout << "do : " << l1 << " " << r1 << " " << l2 << " " << r2 <<'\n';
// 	cout << f[1] << " " << f[2] <<'\n';
//     for (int i = l1; i <= r1; i++) {
//         ll res1 = f[i];
// 		for (int j = l2; j <= r2; j++) {
//             cout << "fight: " << i << " " << j <<'\n';
// 			res1 *= res2 * (a[i]/(a[i]+a[j]));
// 		}
// 	}
    ldb pp[130];
    for (int i = l1; i <= r1; i++) {
        ldb x = 0;
		for (int j = l2; j <= r2; j++) {
//             cout << "fight: " << i << " " << j <<'\n';
			x += f[i] * f[j] * (a[i]/(a[i]+a[j]));
		}
        pp[i] = x;
	}
    for (int j = l2; j <= r2; j++) {
        ldb x = 0;
        for (int i = l1; i <= r1; i++) {
            x += f[i] * f[j] * (a[j]/(a[i] + a[j]));
        }
        pp[j] = x;
    }
    
    for (int i = l1; i <= r1; i++) {
        f[i] = pp[i];
    }
    for (int i = l2; i <= r2; i++) {
        f[i] = pp[i];
    } 
//     cout << "do ans:\n";
//     for (int i = 1; i <= n; i++) {
//         cout << f[i] << " \n"[i==n];
//     }
}

void dfs(int p, int l, int r) {
	if (l == r) {f[l] = 1; return ;}
	int mid = (l + r) / 2;
    if (l <= mid) dfs(lp, l, mid);
	if (r > mid)  dfs(rp, mid + 1, r);
    merge(p);
}


void solve(int CaseT = 1) {
	cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
	
	build(1, 1, n);
	dfs(1, 1, n);
	
	cout << fixed << setprecision(9);
	for (int i = 1; i <= n; i++) {
		cout << f[i] << '\n';
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
