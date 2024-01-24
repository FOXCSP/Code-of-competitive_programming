#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;
double pi = acos(-1);
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	double a, b;
	cin >> a >> b;
	a += b;
	cout << fixed << setprecision(10) << pi * a * a << '\n'; 
	return 0; 
} 
