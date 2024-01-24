#include <bits/stdc++.h>
#define vec vector
#define se second
#define fi first
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;

int a[] = {0,5,6,8,6,9,1,6,1,2,4,9,1,9,8,2,3,6,4,7,7,5,9,5,0,3,8,7,5,8,1,5,8,6,1,8,3,0,3,7
	,9,2,7,0,5,8,8,5,7,0,9,9,1,9,4,4,6,8,6,3,3,8,5,1,6,3,4,6,7,0,7,8,2,7,6,8,9,
	5,6,5,6,1,4,0,1,0,0,9,4,8,0,9,1,2,8,5,0,2,5,3,3};
int dp[110][10], cnt[10];

void solve (int Case) {
//	for (int i = 1; i <= 8; i++) {
//		for (int j = 1; j <= 100; j++) {
//			for (int k = 1; k <= 100; k++) {
//				dp[j][i+1] = dp[k][i] * 10 + a[j];
//			}
//		}
//	}
//	cout << dp[100][8] << "\n";
	for (int i = 1; i <= 100; i++) {
		if (a[i] != 2 && a[i] != 0 && a[i] != 3) {
			continue;
		}
		cout << a[i] << " ";
	}
	cout << '\n';
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
