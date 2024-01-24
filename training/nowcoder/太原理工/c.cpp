#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define pb push_back
#define all(T) T.begin(), T.end()
#define SZ(T) (int)(T.size()) 
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

struct node {
	char a;
	int b;
	bool operator < (const node &R)  const {
		if (a != R.a) return a < R.a;
		else return b < R.b; 
	}
};
void solve(int CaseT = 1) {
	int k;

	cin >> k;
	string s1, s2, s3; 
	cin >> s1 >> s2 >> s3;
	
	ll ans =0;
	for (int i = 0; i < k; i++) {
		int x = 0;
		map<char, int> mp;
		
		mp[s1[i]]++;
		mp[s2[i]]++;
		mp[s3[i]]++;
		
		ans += SZ(mp) - 1; 
	}
	cout << ans <<'\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_ = 1;
//	cin >> _;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}
