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
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < SZ(s); i++) {
		for (int j = 0; j < SZ(s); j++) {
			string a = s.substr(i, j - i + 1);
			string b = a;
			reverse(all(b));
			if (a == b) {
				ans = max(ans, SZ(a));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
