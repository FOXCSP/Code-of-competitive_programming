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

string findMin(string s) {
	int n = SZ(s);
	s = "#" + s + s;
	int i = 1, j = 2;
	while (j <= n) {
		int k = 0;
//		cout << i << " " << j << '\n';
		while (k < n && s[i + k] == s[j + k])
		 ++k;
		if (s[i + k] < s[j + k])
			j += k + 1;
		else
			i += k + 1;
		if (i == j) j++;
		if (i > j)
			swap(i, j);
	}
	string res = "";
//	cout << i << " " << j << " xxx\n";
	for (int l = i; l <= i + n - 1; l++)
		res.pb(s[l]);
	return res;
} 

void solve(int CaseT) {
	string a, b;
	cin >> a >> b;
	if (findMin(a) == findMin(b))
		cout << "Yes\n";
	else 
		cout << "No\n";
}	

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;
//   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
