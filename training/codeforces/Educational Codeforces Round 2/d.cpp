#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
#define P(T) pair<T, T>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
// head

typedef pair<ldb, ldb> point;
ldb pi = acos(-1);


ldb dis(point a, point b) {
	return sqrtl((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}

void solve(int CaseT) {
	ldb x1, y1, x2, y2, r1, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	ldb d = dis({x1, y1}, {x2, y2}); 
	if (d >= r1 + r2) {
//		cout <<" x\n";
		cout << fixed << setprecision(20)<< 1.0*0<<'\n';
	} else if (r1 + d <= r2 || r2 + d <= r1) {
//		cout << " y\n";
		cout << fixed << setprecision(20)<<min(pi * r1 * r1, pi * r2 *r2) <<'\n';
	} else {
//		cout << " z\n";
		ldb ans1 = 0, ans2 = 0;
		ldb angle1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * d * r1)) * 2;
		ldb angle2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * d * r2)) * 2;
		ans1 = 1.0 * r1 * r1 * angle1 - 1.0 * r1 * r1 * sin(angle1);
		ans2 = 1.0 * r2 * r2 * angle2 - 1.0 * r2 * r2 * sin(angle2);
		cout << fixed << setprecision(20)<<(ans1+ans2)/2<<'\n';
	}
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _=1;
//  cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
