#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2100100;
ll n, m;
int cnt, prime[N];
bool vis[N];

void Prime() {
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) prime[cnt++] = i;
		for (int j = 0; j < cnt && prime[j] * i <= N; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

void solve() {
	cin >> n;
	ll a = 0, b = 0;
	map<int, int> mp;
	for (int i = 0; i < cnt; i++) {
		int p = prime[i];
		if (n % p == 0) {a = p; break;}
	}
	if (n % (a * a) == 0) { b = n / (a * a); }
    else b = sqrt(n/a), swap(a, b);
	cout << a << ' ' << b << '\n';
}

int main() {
	Prime();
	int _; cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}