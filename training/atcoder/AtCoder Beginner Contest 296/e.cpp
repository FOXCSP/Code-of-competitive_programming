#include <bits/stdc++.h>
#define fi first
#define se second
#define db double
#define lp (p<<1)
#define rp (p<<1|1)
#define vec vector
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define setdb cout<<fixed<<setprecision(12);
using namespace std;
typedef long long ll;
ll qmi(ll a, ll b, ll mod)
{ll res=1; while(b) { if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;} return res;}
/* -- head -- */

const int N = 200010;
int n;
vec<int> e[N];
void solve(int Tcase = 1) {
	cin >> n;
	vec<int> a(n + 1, 0);
	vec<int> idg(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		idg[a[i]]++;
		e[i].pb(a[i]);
	}

	queue<int> que;
	for (int i = 1; i <= n; i++) {
		if (!idg[i]) que.push(i);
	}
	int ans = n;

	while (!que.empty()) {
		int t = que.front();
		que.pop();
		ans--;
		for (auto v : e[t]) {
			if (--idg[v] == 0) {
				que.push(v);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _; 
	_=1;
//	cin >> _;
	for (int i = 1; i <= _; i++) solve(i);
	return 0;
}
