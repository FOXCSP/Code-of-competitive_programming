#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	if(n == 1 || m == 1) cout << "1 1\n";
	else {
		if(n <= 3 && m <= 3) cout << "2 2\n";
		else cout << "1 1\n";
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}