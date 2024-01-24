#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define all(T) T.begin(), T.end()
#define pb push_back 
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

const int N = 110; 
int n, m;
int a[N][N], f[N][N], b[N][N];
void solve(int CaseT = 1) {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			cin >> b[i][j];
			
	int t = 4;
	for (; t--; ) {
		memcpy(f, a, sizeof a);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) 
				a[i][j] = f[n + 1 - j][i];

		bool ok = 1;
		
		for (int i = 1; i <= n && ok; i++)
			for (int j = 1; j <= n && ok; j++)
				if (a[i][j] && !b[i][j]) {
					ok = false;
//					if (t == 2) {
//						cout << i << " " << j <<'\n';
//					}
				}

		if (ok) {
			cout << "Yes\n";
			return ;
		}

	}
	cout << "No\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_ = 1;
//	cin >> _;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
} 
