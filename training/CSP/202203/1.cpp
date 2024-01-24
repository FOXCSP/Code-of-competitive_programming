#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> c(n + 1, 0);
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		if (!c[b] && b) ans++;
		c[a] = 1;
	}
	cout << ans << '\n';
	return 0; 
}
