#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
#define P(T) pair<T, T> 
#define vec vector
#define fi first
#define se second
#define pb push_back
#define all(T) T.begin(), T.end()
using namespace std;
typedef long long ll;
const int N = 100010;
const ll mod = 1000000007;

/*
6
9 R
10 L
3 R
1 R
3 R
4 L

10
*/

int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vec<P(ll)> vx;
	ll p = 0;
	for (int i = 1; i <= n; i++) {
		ll x;
		char f;
		cin >> x >> f;
		if (f == 'L') vx.pb({p - x, p}), p = p - x;
		else vx.pb({p, p + x}), p = p + x;
	}
	
	sort(all(vx));
	
//	for (auto [x, y] : vx) {
//		cout << x << " " << y << '\n';
//	} 

	priority_queue<P(ll), vec<P(ll)>, greater<P(ll)>> heap;
	
	for (auto x : vx)
		heap.push(x); 
	
	auto [l, r] = heap.top(); heap.pop();
	ll ans = 0;
	
	while (!heap.empty()) {
		auto [x, y] = heap.top(); heap.pop();
		if (y <= l) continue;
		if (x >= r) {
			l = x, r = y;
			continue;
		}
		
		//    l   r
		//  x   y 
		
		//  l    r
		//    x    y  
		
		if (y <= r) {
			ans += y - max(l, x);
			l = y;
		} else {
			ans += r - max(l, x);
			l = r;
			r = y;
		}
	}

	cout << ans << '\n';
	return 0;
}
