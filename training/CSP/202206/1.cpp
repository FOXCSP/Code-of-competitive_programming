#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
  int n, m;
  cin >> n;
  vector<double> a(n + 1, 0);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  double s = 0;
  for (int i = 1; i <= n; i++)
    s += a[i];
  
  s /= n;

  double d = 0;
  for (int i = 1; i <= n; i++) {
    d += (a[i] - s) * (a[i] - s);
  }

  d /= n;

  cout << fixed << setprecision(16);
  for (int i = 1; i <= n; i++) {
    cout << (a[i] - s) / (sqrt(d)) << '\n';
  }
	
	return 0;
} 
