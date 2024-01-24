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

const int N = 200010;
int n, k;
int x[N], c[N];

void solve(int CaseT) {
//	cin >> n >> k;
	srand((unsigned(time(0)))); 
	n = rand() % 20 + 3;
	k = rand() % 20 + 1;
	cout << n << " " << k << '\n';
	x[1] = 3;
	for (int i = 2; i <= k; i++) {
		x[i] = x[i - 1] + rand() % 4 + 1;
		if (x[i] > n) 
			x[i] = n;
	}
	c[1] = 3;
	for (int i = 2; i <= k; i++) {
		c[i] = c[i - 1] + rand() % 4 + 1;
		if (x[i] == n)
			c[i] = c[i - 1];
	}
	
	for (int i = 1; i <= k; i++)
		cout << x[i] << " \n"[i == k];
	for (int i = 1; i <= k; i++)
		cout << c[i] << " \n"[i == k];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;
  cout << 1 << '\n';
//   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}

/*
1
10 2
5 10
5 6

*/
