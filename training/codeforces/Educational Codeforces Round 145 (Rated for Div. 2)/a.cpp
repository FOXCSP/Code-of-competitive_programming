#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define P(T) pair<T, T>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
using ll = long long;

const int inf = 1e9, mod = 998244353;

const int N = 55;

void solve(int caseT = 1) {
	string s;
	cin >> s;
	map<char, int> mp;
	for (char x : s) {
		mp[x]++;
	}
	if (SZ(mp) == 1) {
		cout << "-1\n";
		return ;
	}
	
	int a = 0, b = 0;
	for (auto [x, y] : mp) {
		if (y == 1) a++;
		if (y == 2) b++;
	}
	if (a >= 2 || b >= 1) {
		cout << "4\n";
	} else {
		cout << "6\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	cin >> _;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	
	return 0;
}

