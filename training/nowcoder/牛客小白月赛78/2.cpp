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
	int a, b, c, d;
	a = b = c = d = 0;
	string s;
	cin >> s;
	int ans = 0;
	for (auto x : s) {
		if (x == 'a') d++;
		if (x == 'b') b++;
		if (d == 10) c++, d = 0;
		if (b == 10) a++, b = 0;
		ans += (!a)+(!b)+(!c)+(!d);
	}
	cout << ans << '\n';
	return 0; 
} 
