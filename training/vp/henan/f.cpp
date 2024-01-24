#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10, INF = 2e18;
int a[N];
map<int, int> mp;
multiset<int> st;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >>n >> k;
	bool ok = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(mp[a[i]])	ok = 0;
		mp[a[i]] = 1;
	}
	sort(a + 1, a + 1 + n);
	int res = INF;
	
	
	for (int i = k; i <= n && ok; i ++) {
		if(i == k) {
			for (int j = 1; j < k; j++) {
				st.insert(a[i-j + 1] - a[i-j]);
			}
		} else {
			st.erase(st.find(a[i-k+1] - a[i-k]));
			st.insert(a[i] - a[i-1]);
		}
		res = min(res, (*st.begin()) * (a[i] - a[i-k+1]));
	}
	
	if(!ok)	res = 0;
	cout << res << "\n";
	return 0;
}

