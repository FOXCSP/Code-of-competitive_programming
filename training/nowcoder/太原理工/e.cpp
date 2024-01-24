#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define pb push_back
#define all(T) T.begin(), T.end()
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

void solve(int CaseT = 1) {
	string a, b;
	cin >> a >> b;
	if (SZ(a) != SZ(b)) {
        if (abs(SZ(b) - SZ(a)) != 1) {
            cout << "NO\n";
            return ;
        }
        bool f = 0;
        int t = 0;
		int len  = SZ(a);
		len = min(len, SZ(b)); 
		if (SZ(a) < SZ(b)) swap(a, b);
		for (int i = 0; i < len; i++) {
			if (f == 0 && a[i] != b[i]) {
				f = 1;
				if (b[i] == a[i + 1]) {t = 1;}
				else if (i && b[i] == a[i - 1]) {t = 2;}
                else {
                    cout << "NO\n";
                    return ;
                }
			}

			if (f) {
				if (t == 1 && b[i] != a[i + 1]) {
					cout << "NO\n";
					return ;
				}
				if (t == 2 && i && b[i] != a[i - 1]) {
					cout << "NO\n";
					return ;
				}
			}
		}
		cout << "YES\n";
	} else {
		int t = 0;
		for (int i = 0; i < SZ(a); i++) {
			if (a[i] != b[i]) t++;
			if (t > 1) {
				cout << "NO\n";
				return ;
			}
		}
		cout << "YES\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_ = 1;
//	cin >> _;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}
