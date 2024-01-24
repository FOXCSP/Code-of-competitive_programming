#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;
double pi = acos(-1);
int k, a, b;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> k >> a >> b;
	set<int> S;
	for (auto it = S.begin(); SZ(S) <= 2 * k; it = next(it)) {
		S.insert(*it + a);
		S.insert(*it + b);
	}
	auto it = S.begin();
	for (int i = 1; i <= k; i++) {
		it = next(it);
	}
	cout << *it << '\n';
	return 0; 
} 
