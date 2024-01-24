#include <bits/stdc++.h>
#define MAXN 100001
#define MAXVALUE 110
using namespace std;
int a[10001];
int b[10001];
int c[10001];
int n;
set<int> S;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]] = i;
		S.insert(a[i]);
		c[i] = a[i];
	}
	sort(c + 1, c + 1 + n);
	long long ans = 0;
	int MIN = *min_element(a + 1, a + n + 1);
	while (S.size()) {
		int minx = *S.begin();
		S.erase(S.begin());
		long long sum = 0;
		long long cnt = 1;
		while (b[minx] != (lower_bound(c + 1, c + n + 1, minx) - c)) {
			S.erase(S.find(c[b[minx]]));
			sum += c[b[minx]];
			b[minx] = b[c[b[minx]]];
			cnt++;
		}
		ans += sum + min((cnt - 1) * minx, (cnt - 1) * MIN + 2 * (MIN + minx));
	}
	cout << ans << '\n';
	return 0;
}
