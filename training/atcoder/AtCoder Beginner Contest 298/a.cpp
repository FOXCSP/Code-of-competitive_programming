#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define all(T) T.begin(), T.end()
#define pb push_back 
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

const int N = 100010;

int n, m;
int p[N];
ldb xe, ye;
ldb dis(ldb x1, ldb y1, ldb x2, ldb y2) {
	return sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); 
}

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void solve(int CaseT = 1) {
	cin >> n;
	string s;
	cin >> s;
	int a= 0, b = 0;
	for (auto x : s) {
		a += (x == 'o');
		b += (x == 'x');
	}
	if (a && !b) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
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
