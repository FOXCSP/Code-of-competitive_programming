#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;
double pi = acos(-1);
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int k, a, b;
	cin >> k >> a >> b;
	if (a == b) {
		cout << a * k << '\n';
	} else {
		int pos = 1, cur = 2;
		while (1) {
			if (cur + 2 * cur - 1 <= k) cur += 2 * cur - 1, pos++;
			else break;
		}
		cout << pos << '\n';
	}
	return 0; 
} 
