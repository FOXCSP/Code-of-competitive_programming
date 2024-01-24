#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

void solve() {
	int n, res = 0, k = 0;
	cin >> n;
	for (int i = 0; k + (1 << i) < n; i++) {
        k += 1 << i;
        res++;
    }
	cout << res + (n > (1 << res)) << '\n';
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
