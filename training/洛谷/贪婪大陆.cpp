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

const int N = 100010;
int c1[N], c2[N];
int n, m;
void modify1(int x, int y) {
	for (; x <= n; x += x & -x) 
		c1[x] += y;
}
int query1(int x) {
	int s = 0;
	for (; x; x -= x & -x)
		s += c1[x];
	return s;
}

void modify2(int x, int y) {
	for (; x <= n; x += x & -x) 
		c2[x] += y;
}
int query2(int x) {
	int s = 0;
	for (; x; x -= x & -x)
		s += c2[x];
	return s;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int q, l, r;
		scanf("%d%d%d", &q, &l, &r);
		if (q == 1) {
			modify1(l, 1);
			modify2(r, 1);
		} else {
			int ans = query1(r) - query2(l - 1);
			printf("%d\n", ans);
		}
	}
	return 0;
} 
