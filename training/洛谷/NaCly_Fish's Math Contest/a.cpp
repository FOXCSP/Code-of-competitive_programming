#include <bits/stdc++.h>

using namespace std;
using LL = long long;
const int mod = 998244353;
int n, k;
LL qmi(int a, int b) {
	LL res = 1;
	while(b) {
		if(b& 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

void solve () {
	cin >> n >> k;
	LL t = qmi(2, n);
	LL sum = qmi(t, k);
	cout << 
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
	return 0;
}