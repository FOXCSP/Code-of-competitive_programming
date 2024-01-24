#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define fi first
#define se second

typedef pair<int,int> PII;

typedef pair<int, int> pii;
#define x first
#define y second
#define inf 0x3f3f3f3f
void solve() {
}
int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0), cout.tie(0);
	solve();
	ll q = 5e18;
	ll t = 0;
	for (ll x = 0; x < 64; x++) {
		t += (1ll << x);
		if (t > q) {
			cout << x << '\n';
			break;
		}
	}
	return 0;
}