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
	int n, m;
	cin >> n >> m;
	vector<string> vs;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vs.pb(s);
	}
	int ans = 0, res = 0;
	for (int i = 0; i < m; i++) {
		bool f = 1;
		for (int j = 0; j < n && f; j++)
			if (vs[j][i] == 'x')
				f = false;
		if (f) res++;
		else res = 0;
		
		if (f) {
			ans = max(ans, res);
		}
	}
	cout << ans << '\n';
	return 0;
}
