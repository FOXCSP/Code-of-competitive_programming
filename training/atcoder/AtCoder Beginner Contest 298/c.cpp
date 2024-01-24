#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define all(T) T.begin(), T.end()
#define pb push_back 
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

const int N = 200010; 
int n, m;
multiset<int> box[N];
set<int> card[N];
void solve(int CaseT = 1) {
	cin >> n >> m;
	for (; m--;) {
		int op, i, j;
		cin >> op;
		if (op == 1) {
			cin >> i >> j;
			box[j].insert(i);
			card[i].insert(j); 
		}
		
		if (op == 2) {
			cin >> i;
			for (auto x : box[i]) {
				cout << x << " ";
			}
			cout << '\n';
		}
		
		if (op == 3) {
			cin >> i;
			for (auto x : card[i]) {
				cout << x << " ";
			}
			cout << '\n';
		}
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
