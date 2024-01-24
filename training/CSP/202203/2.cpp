#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;
const int N= 1000010;
int t[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		int l = max(1, a - b + 1 - k);
		int r = a - k;
		if (r <= 0) continue;
		t[l]++;
		t[r + 1]--;
	}
	for (int i = 1; i <= 1000000; i++) {
		t[i] += t[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		cout << t[x]<< '\n';
	}
	return 0; 
}
