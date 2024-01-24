#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define pb push_back
#define se second
#define fi first
using namespace std;

char a[10][10];
void solve() {
	for (int i = 1; i <= 8; i++)
		cin >> a[i] + 1;
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++) {
			if (a[i][j] != '.') {
				for (int k = i; k <= 8 && a[k][j] != '.'; k++) {
					cout << a[k][j];
				}
				cout << '\n';
				return ;
			}
				
		}
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
