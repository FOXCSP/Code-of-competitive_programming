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

void solve(int Tcase = 1) {
	string s;
	int n;
	cin >> n;
	cin >> s;
	
	vec<int> pos[26];
	for (int i = 0; i < n; i++) {
		pos[s[i] - 'a'].pb(i);
	}
	for (int i = 0; i < 26; i++) {
		if (SZ(pos[i]) > 1) {
			for (int j = 1; j < SZ(pos[i]); j++) {
				if (pos[i][j]%2 != pos[i][j - 1]%2) {
					cout << "NO\n";
					return ;
				}
			}
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _; 
	cin >> _;
	for (int i = 1; i <= _; i++) solve(i);
	return 0;
}
