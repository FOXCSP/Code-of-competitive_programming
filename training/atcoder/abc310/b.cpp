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
	vector<int> c(n + 1, 0), p(n + 1, 0);
	vector<int> vx[110];
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> c[i];
		for (int j = 1; j <= c[i]; j++) {
			int x;
			cin >> x;
			vx[i].pb(x); 
		}
	}
	
	auto ck = [&](int x, int y) {
		if (p[x] < p[y]) return false;
		map<int, int> mp;
		for (auto t : vx[y])
			mp[t]++;
		for (auto t : vx[x])
			if (mp[t] == 0)
				return false;
		if (c[x] == c[y])
			return p[x] > p[y];
		return true;
	};
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (ck(i, j)) {
				cout << "Yes\n";
				return 0;
			}
	cout << "No\n";
	return 0;
}
