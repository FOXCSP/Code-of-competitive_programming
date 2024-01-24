#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int s[N], n, cnt, mins[N], minr[N], a[N];
int main() {
	scanf("%d", &n);
	mins[0] = 1 << 30;
	minr[n+1] = 1 << 30;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
		mins[i] = min(mins[i - 1], s[i]);
	}
	for (int i = n; i >= 1; i--) 
		minr[i] = min(minr[i + 1], s[i]);
	for (int k = 1; k <= n; k++) {
		if (mins[k - 1] + s[n] - s[k - 1] >= 0 &&
			minr[k] - s[k - 1] >= 0) 
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}