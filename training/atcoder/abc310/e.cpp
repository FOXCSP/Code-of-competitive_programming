#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 50;
const ll mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	string s;
	cin >> n >> s;
	s = "#" + s;
	ll ans = 0, cnt = 0;
	for (int i = n; i; i--) {
		if (s[i] == '1') {
			ans += n - i + 1 - cnt; 
		} else {
			ans += n - i;
		}
		
		if (s[i] == '1') 
			cnt++;
		cout << ans << " " << cnt << '\n';
	}
	
	cout << ans << '\n';
	
	return 0;
}
