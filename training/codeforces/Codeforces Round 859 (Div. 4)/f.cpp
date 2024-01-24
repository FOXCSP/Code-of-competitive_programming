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

int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};

void solve(int Tcase = 1) {
	int n, m;
	P(int) s, t;
	cin >> n >> m >> s.fi >> s.se >> t.fi >> t.se;
	string to; cin >> to;
	
	map<string, int> mp;
	
	mp["DR"] = 0;
	mp["DL"] = 1;
	mp["UR"] = 2;
	mp["UL"] = 3;
	
	P(int) now = s;
	
	int res = 0;
	
	
	map<tuple<int, int, string>, int> our;
	
	while (1) {
		P(int) nxt;
		
		if (now == t) {
			cout << res << '\n';
			return ;
		}

		
		int cur = 0;
		
		if (now.fi == 1 && to[0] == 'U') to[0] = 'D', cur++;
		if (now.fi == n && to[0] == 'D') to[0] = 'U', cur++;
		if (now.se == 1 && to[1] == 'L') to[1] = 'R', cur++;
		if (now.se == m && to[1] == 'R') to[1] = 'L', cur++;
		
		res += (cur!=0);
		
		nxt.fi = now.fi + dx[mp[to]];
		nxt.se = now.se + dy[mp[to]];
		
		
		tuple<int, int, string> x, y;
		x = {now.fi, now.se, to};
		y = {nxt.fi, nxt.se, to};
		
		if (our[x] && our[y]) {
			break;
		}
		
		our[x]++;
		our[y]++;
		
		now = nxt;
	}
	cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int _; 
	cin >> _;
	for (int i = 1; i <= _; i++) solve(i);
	return 0;
}
