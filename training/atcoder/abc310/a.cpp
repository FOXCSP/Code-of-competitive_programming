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
	
	ll n, q, p;
	cin >> n >> p >> q;
	ll ans = p;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		ans = min(ans, q + x);
	}
	cout << ans <<'\n'; 
	
	return 0;
}
