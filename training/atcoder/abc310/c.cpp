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
	
	int n, id = 0;
	cin >> n;
	map<ll, ll> mp;
	for (int i = 1; i <= n; i++) {
		ll hs1 = 0, hs2 = 0;
		string s;
		cin >> s;
		for (int i = 0; i < SZ(s); i++) 
			hs1 = (hs1 * 1331 + s[i]) % mod;
		if (mp.count(hs1) == 0)
			mp[hs1] = id++;
		hs2 = 0;
		for (int i = SZ(s) - 1; i >= 0; i--)
			hs2 = (hs2 * 1331 + s[i]) % mod;
		mp[hs2] = mp[hs1];
	}
	
	cout << id << '\n';
	return 0;
}
