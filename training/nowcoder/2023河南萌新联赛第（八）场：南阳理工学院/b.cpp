#include <bits/stdc++.h>
#define int long long
#define se second
#define fi first
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;
typedef long long ll;

const int N = 500010;
const ll mod = 1000000007;
int n;
int c[N];

void modify(int x, int y) {
	for (x; x <= N - 1; x += x & -x)
		c[x] += y;
}

int query(int x) {
	int s = 0;
	for (; x; x -= x & -x)
			s += c[x];
	return s;
}

int t[N];

void modify2(int x, int y) {
	for (x; x <= N - 1; x += x & -x)
		t[x] += y;
}

int query2(int x) {
	int s = 0;
	for (; x; x -= x & -x)
			s += t[x];
	return s;
}

ll qmi(int a, int b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int l, r;
		l = max(a, c);
		r = min(b, d);
		if (l <= r) {
			modify(l, 1);
			modify(r + 1, -1);
			modify2(min(a, c), 1);
			modify2(max(b, d) + 1, -1); 
		} else {
			modify2(a, 1);
			modify2(b + 1, -1);
			modify2(c, 1);
			modify2(d + 1, -1);
		}
	}
	ll ans = 0;
	for (int i = 1; i <= N - 1; i++) {
		int q = query2(i);
		if (q == n) {
			int p = query(i);
      ans = (ans + qmi(2, p)) % mod;
		}
	}
	cout << ans << '\n';
	return 0;
}