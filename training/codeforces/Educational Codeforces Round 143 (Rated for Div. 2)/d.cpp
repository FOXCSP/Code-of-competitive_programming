#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

// --head--

const ll mod = 998244353;

ll qmi(int a, int k)
{
    ll res = 1;
    while (k)
    {
        if (k & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        k >>= 1;
    }
    return res;
}


ll C(int a, int b)
{
    if (b > a) return 0;

    ll res = 1;
    for (int i = 1, j = a; i <= b; i ++, j -- )
    {
        res = 1ll * res * j % mod;
        res = 1ll * res * qmi(i, mod - 2) % mod;
    }
    return res;
}


ll lucas(ll a, ll b)
{
    if (a < mod && b < mod) return C(a, b);
    return (ll) C(a % mod, b % mod) * lucas(a / mod, b / mod) % mod;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a.pb(x);
		if (SZ(a) == 3) {
			sort(a.begin(), a.end());
			if (a[0] == a[1] && a[1] == a[2]) cnt1++;
			if (a[0] == a[1] && a[1] < a[2]) cnt2++;
			a.clear();
		}
	}
	ll ans = 1;
	ans = (C(n / 3, n / 6) * qmi(3, cnt1) % mod * qmi(2, cnt2) + mod) % mod;
	cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _;
    _=1;
    while (_--) solve();
    return 0;
}
