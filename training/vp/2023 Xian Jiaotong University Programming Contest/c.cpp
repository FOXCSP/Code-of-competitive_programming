#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double lbd;
// head
void solve(int CaseT) {
	int a, b, c;
	cin >> a >> b >> c;
	printf("%.06f\n", 1.0 * c / (a * b));
}

int main() {
	int _;
	_=1;
//	cin>>_;
	for (int i = 1; i <= _; i++)
		solve(i);
	return 0;
}

