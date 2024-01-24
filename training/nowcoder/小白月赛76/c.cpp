// a = k * b + m
// b
// a + b = n
// k * b + m + b = (k + 1) * b + m = n
#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	cin >> n >> m;
	if (m < n - m) {
        cout << m << " " << n - m << '\n';
        return ;
    }
    cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _ = 1;
	cin >> _;
	
	for ( ; _--; )
		solve();
	return 0;
}
