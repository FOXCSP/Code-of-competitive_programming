#include <bits/stdc++.h>

using namespace std;
using ll = long long;


const int N = 1000010, mod = 1e9 + 7;
int prime[N];
bool vis[N];
int cnt;

void Prime(int n) {
	for(int i = 2; i <= n;i ++) {
		if(!vis[i]) prime[cnt ++] = i;
		for(int j = 0; j < cnt && i * prime[j] <= n; j ++) 	{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
 	}
}


void solve() {
	int n; cin >> n;
	Prime(n);
	ll ans = 1;
	for(int i = 0;i < cnt; i ++) {
		int p = prime[i];
		int s = 0;
		for(int j = n; j; j /= p) s += j / p;
		ans = (ans * (s * 2 + 1)) % mod;
	}
	cout << ans << '\n';
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}