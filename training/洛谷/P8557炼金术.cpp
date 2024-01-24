#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 998244353;

ll qmi(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		b >>= 1;
		a = (a * a) % mod; 
	}
	return res % mod;
}

int main() {
	ll n, k;
	cin >> n >> k;
	cout << qmi((qmi(2, k) - 1) % mod, n) % mod << '\n';
	return 0;
}d