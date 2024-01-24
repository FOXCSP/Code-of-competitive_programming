#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200010;
int a[N], s[N];
int n, m; 
int f[N][20];
void ST() {
    for(int i = 1;i <= n;i ++) f[i][0] = a[i];
    int t = log(n)/log(2)+1;
    for(int j = 1;j < t;j ++)
        for(int i = 1;i <= n - (1<<j)+1; i ++) 
            f[i][j] = max(f[i][j-1], f[i + (1 <<(j -1))][j-1]);
}

int query(int l,int r) {
    int k = log(r - l + 1) / log(2);
    return max(f[l][k], f[r - (1<<k) + 1][k]);
}

int find(int l, int r, int k) {
	if(l == r)	return l;
	int mid = l + r >> 1;
	if(query(l, mid) > k) return find(l, mid, k);
	return find(mid + 1, r, k);
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	ST();
	while(m --) {
		int k; cin >> k;
		int idx = find(1, n, k);
		if(a[idx] > k) idx --;
		cout << s[idx] << " \n"[m == 0];
	}
}
signed main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _; cin>>_; while(_--) solve();
	return 0;
}