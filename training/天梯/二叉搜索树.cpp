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
#define setdb cout<<fixed<<setprecis ion(12);
using namespace std;
typedef long long ll;
ll qmi(ll a, ll b, ll mod)
{ll res=1; while(b) { if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;} return res;}
/* -- head -- */

const int N = 1010;
int a[N], n;

bool dfs(int l, int r) {
	
	if (l > r) return true;
	int root = a[l];
	int pos = r + 1;
	
	for (int i = l + 1; i <= r; i++) {
		if (a[i] >= root) {
			pos = i;
			break;
		}
	}
	
	for (int i = pos; i <= r; i++) {
		if (a[i] < root) {
			return false;
		}
	}
	
	return (dfs(l + 1, pos - 1) & dfs(pos, r));
}

bool dfs3(int l, int r) {
	if (l > r) return true;
	int root = a[l];
	int pos = r + 1;
	
	for (int i = l + 1; i <= r; i++) {
		if (a[i] < root) {
			pos = i;
			break;
		}
	}
	
	for (int i = pos; i <= r; i++) {
		if (a[i] >= root) {
			return false;
		}
	}
	
	return (dfs3(l + 1, pos - 1) & dfs3(pos, r));
}


void dfs2(int l, int r, int ty) {
	if (l > r) return ;
	if (ty == 1) {
		int root = a[l];
		if (l < r) {
			int pos = r + 1;
			for (int i = l + 1; i <= r; i++) {
				if (a[i] >= root) {
					pos = i;
					break;
				}
			}
			
			if (l + 1 <= pos - 1) dfs2(l + 1, pos - 1, ty);
			if (pos <= r) dfs2(pos, r, ty);
		}
		if (l == 1 && r == n) cout << root;
        else cout << root << " ";
        
	} else {
		int root = a[l];
		if (l < r) {
			int pos = r + 1;
			for (int i = l + 1; i <= r; i++) {
				if (a[i] < root) {
					pos = i;
					break;
				}
			}
			
			if (l + 1 <= pos - 1) dfs2(l + 1, pos - 1, ty);
			if (pos <= r) dfs2(pos, r, ty);
		}
		if (l == 1 &&  r == n) cout << root;
        else cout << root << " ";
	}
}

void solve(int Tcase = 1) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int f = dfs(1, n);
	int g = dfs3(1, n);
	if (f || g) {
		cout << "YES\n";
		if (f) dfs2(1, n, 1);
		else if (g) dfs2(1, n, 0);
        cout << '\n';
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _; 
	//	cin >> _;
	_=1;
	for (int i = 1; i <= _; i++) solve(i);
	return 0;
}