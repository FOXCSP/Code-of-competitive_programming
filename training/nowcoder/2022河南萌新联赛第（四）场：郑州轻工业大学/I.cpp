#include <bits/stdc++.h>
#define fi first
#define se second
#define sf scanf
#define pf printf
#define int long long
using namespace std;

typedef pair<int,int> PII;
/*--code --*/

const int N = 1e5 + 10;

int n, k;
int p[N], v[N], t[N];
PII ants[N];
// bool cmp(PII a, PII b) {
// 	return a.fi < b.fi;
// }
bool check(int mid) {
	int cnt = 0;
	for(int i = 1;i <= n;i ++) {
		t[i] = ants[i].fi+mid*ants[i].se;
	}
	// 统计相对位置改变数量
	int res = t[1];
	for(int i = 1;i <= n;i ++) {
		res = max(res, t[i]);
		if(t[i] < res) cnt ++;
	}
	if(cnt<n-k) return false;
	return true;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) cin >> ants[i].fi;
	for(int i = 1;i <= n;i ++) cin >> ants[i].se;
    sort(ants+1,ants+n+1);
	int l = 0, r = 1000001000;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(r == 1000001000) cout << "Never!" << endl;
	else cout << l << endl;
    return 0;
}
