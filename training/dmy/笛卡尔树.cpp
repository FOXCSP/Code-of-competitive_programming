#include <bits/stdc++.h>
// #define int long long

using namespace std;
using ll = long long;

const int N = 10000010;
int tot, n;
int l[N], r[N], a[N];
// 单调栈

ll cnt1 = 0, cnt2 = 0;

inline int read() {
    int num = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        num = num * 10 + c - '0';
        c = getchar();
    }
    return num;
}

void dfs(int u) {
	if (l[u]) { 
		cnt1 ^= (1ll * u * (l[u] + 1));
		dfs(l[u]);
	} else {
		cnt1 ^= (ll)u;
	}
	if (r[u]) {
		cnt2 ^= (1ll * u * (r[u] + 1));
		dfs(r[u]);
	} else {
		cnt2 ^= (ll)u;
	}
}

int stk[N], top;
void build() {
	int root = 0;
	for (int i = 1; i <= n; i++) {
		int last = 0;
		while (top && a[stk[top]] > a[i]) {
			last = stk[top];
			top --;
		}
		if (top) r[stk[top]] = i;
		else root = i;
		l[i] = last;
		stk[++ top] = i;
	}
	dfs(root);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) a[i] = read();
	build();
	printf("%lld %lld\n", cnt1, cnt2);
}

signed main() {
	solve();
	return 0;
}