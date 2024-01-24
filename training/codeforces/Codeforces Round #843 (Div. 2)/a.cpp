#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define fi first
#define se second

int n;
P x, y, z;
vector<int> posa, posb;
void solve() {
	string s; cin >> s;
	n = s.size();
	posa.clear(), posb.clear();
	for (int i = 0; i < n; i++) 
		if (s[i] == 'a') posa.push_back(i); 
		else posb.push_back(i);
	if (s[0] == 'a') {
		if (posa.size() == 1) {
			x = {0, 0}, z = {n - 1, n - 1}, y = {1, n - 2};
		} else if (posa[1] > 1) {
			x = {0, 0}, y = {1, posa[1] - 1}, z = {posa[1], n - 1};
		} else {
			x = {0, 0}, y = {1, 1}, z = {2, n - 1};
		}
	} else {
		if (posb.size() == 1) {
			x = {0, 0}, y = {1, 1}, z = {2, n - 1};
		} else if (posb[1] > 1) {
			x = {0, 0}, y = {1, posb[1] - 1}, z = {posb[1], n - 1};
		} else {
			x = {0, 0}, y = {1, posb.back()};
			if (posb.back() == n - 1) y.se--;
			z = {y.se + 1, n - 1};
		}
	}
	for (int i = x.fi; i <= x.se; i++) cout << s[i];
	cout << " ";
	for (int i = y.fi; i <= y.se; i++) cout << s[i];
	cout << " ";
	for (int i = z.fi; i <= z.se; i++) cout << s[i];
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0), cout.tie(0);
	int _; cin >> _;
	while(_--) {
		solve();
	}
	return 0;
}