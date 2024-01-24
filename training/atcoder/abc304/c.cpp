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

const int N = 2010;
int x[N], y[N], p[N];
double dis(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	double d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	
	for (int i = 1; i <= n; i++)
		p[i] = i;
	
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			if (dis(i, j) <= d) {
				int pi = find(i);
				int pj = find(j);
				if (pi != pj)
					p[pi] = pj;
			}
		}
	
	for (int i = 1; i <= n; i++) {
		if (find(i) != find(1)) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}
	
	
	return 0;
} 
