#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p << 1)
#define rp (p << 1 | 1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

const int N = 10001;
ll Q[N][21], KT[21][N], V[N][21], W[N], ans[N][21], tmp[N];
int d, n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= d; j++) {
			cin >> Q[i][j];
		}
	}  
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= d; j++) {
			cin >> KT[j][i];
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= d; j++) {
			cin >> V[i][j];
		}
		
	for (int i = 1; i <= n; i++)
		cin >> W[i];
		
	for (int i = 1; i <= n; i++) {
		for (int t = 1; t <= n; t++) {
			ll cur = 0;
			for (int j = 1; j <= d; j++) {
				cur += Q[i][j] * KT[j][t];
			}
			tmp[t] = cur;
		}
		
		
		for (int j = 1; j <= n; j++)
			tmp[j] *= W[i];
		for (int t = 1; t <= d; t++) {
			ll cur = 0;
			for (int j = 1; j <= n; j++) {
				cur += tmp[j] * V[j][t];
			}
			ans[i][t] = cur;
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= d; j++)
			cout << ans[i][j] << " \n"[j == d];
	
  return 0;
}
