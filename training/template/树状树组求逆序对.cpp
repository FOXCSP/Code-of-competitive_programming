// https://atcoder.jp/contests/abc296/submissions/40293683
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
int c[N];
int n;
void modify (int x, int y) {
	for (x; x <= n; x += x & -x) c[x] += y;
}
int query(int x) {
	int s = 0;
	for (x; x; x -= x & -x) s += c[x];
	return s;
}

void solve(int Tcase = 1) {
	cin >> n;
	vec<int> a(n), b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	ll res1 = 0, res2 = 0;
	for (int i = n - 1; i >= 0; i--) {
		modify(a[i], 1);
		res1 += query(a[i] - 1);
	}

    for (int i = 1; i <= n; i++) c[i] = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        modify(b[i], 1);
        res2 += query(b[i] - 1);
    }

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	bool f = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			cout << "No\n";
			return ;
		}
		if (i && a[i] == a[i - 1]) {
			f = 1;
		}
	}
	
	if (f) {
		cout << "Yes\n";
		return ;
    }

    cout << ((res1+res2)%2==0? "Yes":"No");
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _; 
	_=1;
//	cin >> _;
	for (int i = 1; i <= _; i++) solve(i);
	return 0;
}
