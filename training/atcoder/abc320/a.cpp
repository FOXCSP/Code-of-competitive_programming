#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 200010;
const ll mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, b;
	cin >> a >> b;
	ll l, r;
	l = 1, r = 1;
	for (int i = 0; i < b; i++) {
		l *= a; 
	}
	for (int i = 0; i < a; i++) {
		r *= b;
	}
	cout << l + r << '\n';
	return 0;
}
