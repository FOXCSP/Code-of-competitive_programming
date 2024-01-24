#include <bits/stdc++.h>
#define fi first
#define se second
#define pb emplace_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

// --head--

bool check(string a, string b) {
	for (int i = 1; i <= 100; i++) {
		if (SZ(b) == 0) break;
		if (a.back() != b.back()) {
			a = a + b.back();
			b.pop_back();
		}
	}
	for (int i = 1; i < SZ(a); i++) {
		if (a[i] == a[i - 1]) {
			return false;
		}
	}
	for (int i = 1; i < SZ(b); i++) {
		if (b[i] == b[i - 1]) {
			return false;
		}
	}
	return true;
}

void solve() {
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	if (check(a, b) || check(b, a)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}