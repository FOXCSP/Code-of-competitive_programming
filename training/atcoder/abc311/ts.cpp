#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 200010;
const ll mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	ll res = 0;
	for (int i = 1, p = 2 * n - 1; i <= n; i++) {
		res += 1ll * i * p;
		p -= 2;
	}
	cout << res << '\n';
	return 0;
}
