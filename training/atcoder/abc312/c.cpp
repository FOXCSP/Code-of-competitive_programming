#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 200010;
const ll mod = 998244353;


int n, m;
int a[N], b[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	auto ck = [&](int x) {
		int l = 0, r = n;
		while (l < r) {
			int M = (l + r + 1) / 2;
			if (a[M] <= x) l = M;
			else r = M - 1;
		}
		int p1 = l;
		l = 0, r = m;
		while (l < r) {
			int M = (l + r + 1) / 2;
			if (b[M] < x) l = M;
			else r = M - 1;
		}
		int p2 = m - l;
		return p1 >= p2;
	};

	int l = 1, r = 1e9 + 10;
	while (l < r) {
		int mid = (l + r) / 2;
		if (ck(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';

	return 0;
}
