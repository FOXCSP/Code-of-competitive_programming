#include <bits/stdc++.h>
#define vec vector
#define se second
#define fi first
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;

const int N = 10010;
int d[N], t[N], l[N];
bool check(int x, int y) {
	return d[x] + l[x] <= d[y] + t[y];
} 

/*
1
2
0 10 21
10 10 20
*/
void solve (int Case) {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "YES\n";
	} else if (n == 2) {
		cin >> d[1] >> t[1] >> l[1];
		cin >> d[2] >> t[2] >> l[2];
		if (check(1, 2) || check(2, 1)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
	cin>>_;
	for (int i=1; i<=_;i++) {
		solve(i);
	}
	return 0;
}
