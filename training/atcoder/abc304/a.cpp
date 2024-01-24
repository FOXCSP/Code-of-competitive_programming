#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int p = 0, mn = 1 << 30;
	
	int n;
	cin >> n;
	string str[110];
	int a[110];
	for (int i = 1; i <= n; i++) {
		cin >> str[i] >> a[i];
		if (a[i] < mn) {
			mn = a[i];
			p = i;
		}
	}	

	for (int i = p; i <= n; i++)
		cout << str[i] << '\n';
	for (int i = 1; i < p; i++)
		cout << str[i] << '\n';	
		
	return 0;
} 
