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
	int n;
	cin >> n;
	vec<node> x;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		x.pb((node){s[1], s[0] - '0'});
	}
	sort(all(x));	
	for (auto [a, b] : x) {
        cout << b << a << " ";
// 		cout << to_string(b) + to_string(a) << " ";
	}
	cout <<'\n';
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
