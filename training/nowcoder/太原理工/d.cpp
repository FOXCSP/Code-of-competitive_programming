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
	string s;
	cin >> s;
	sort(all(s));
	reverse(all(s));
	string a = "", b = "";
	for (int i = 0; i < SZ(s); i++) {
		if (i&1) b.pb(s[i]);
		else a.pb(s[i]);
	}
    reverse(all(a));
    reverse(all(b));
    while (SZ(a) > 1 && a.back() == '0') a.pop_back(); 
    while (SZ(b) > 1 && b.back() == '0') b.pop_back(); 
	reverse(all(a));
    reverse(all(b));
    
    cout << a << "\n" << b <<'\n'; 
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
