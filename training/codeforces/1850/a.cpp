#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())

using namespace std;

void solve() {
	vector<int> a(3, 0);
	int s=  0;
	for (int i = 0; i < 3; i++)
		cin >> a[i], s += a[i];
	for (int i = 0; i < 3; i++) {
		if (s - a[i] >= 10)
			{
				cout << "YES\n";
				return ;
			}
	} 
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int _ = 1;
	cin >> _;
	for (; _--; ) {
		solve();
	}
	
	return 0;
}
