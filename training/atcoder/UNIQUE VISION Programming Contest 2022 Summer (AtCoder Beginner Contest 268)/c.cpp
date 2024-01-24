#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, pos[N], cnt[N];

void solve() {
	cin >> n;
	for(int i = 0;i < n;i ++ ) {
		int x;
		cin >> x;
		pos[x] = i;
	}

	for(int i = 0;i < n; i ++) {
		int v = (pos[i] + n - i) % n;
		cnt[v] ++;
		cnt[(v + 1)%n] ++;
		cnt[(v + 2) % n] ++;
	}

	cout << *max_element(cnt, cnt + n) << '\n';
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}

/*
4
1 2 0 3

0 : n - 1, 0, 1
1 : 1, 2, 0
2 : 1, 2, 3
3 : 2, 3, 4

1
*/