#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

void solve() {
	string s;
	cin >> s;
	if (s[0] == 'b')
		cout << "bu\n";
	
	if (s[0] == 'j')
		cout << "jiandao\n";
		
	if (s[0] == 's')
		cout << "shitou\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _ = 1;
//	cin >> _;
	
	for ( ; _--; )
		solve();
	return 0;
}
