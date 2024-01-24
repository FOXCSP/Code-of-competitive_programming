#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
#define all(T) T.begin(), T.end() 
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
	string sa, sb, sc;
	cin >> sa >> sb >> sc; 
	int ans = 1 << 30;
	for (int i = 0; i < 10; i++) {
		vector<int> a, b, c;
		for (int j = 0; j < n; j++) {
			if (sa[j] - '0' == i) a.pb(j);
			if (sb[j] - '0' == i) b.pb(j);
			if (sc[j] - '0' == i) c.pb(j);
		}
		for (auto x : a) {
			for (auto y : b) {
				for (auto z : c) {
					if (x != y && y != z && x != z) {
						ans = min(ans, max(x, max(y, z)));
					} else if (x == y && y == z) {
						ans = min(ans, x + 2 * n);
					} else if (x == y || y == z || x == z) {
						if (x == y) ans = min(ans, x + n);
						if (y == z) ans = min(ans, y + n);
						if (x == z) ans = min(ans, z + n);
					}
				} 
			}
		}
	}
	cout << (ans == 1 << 30 ? -1 : ans) << '\n';
	return 0;
}
