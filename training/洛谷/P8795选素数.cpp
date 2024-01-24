#include <bits/stdc++.h>

using namespace std;

vector<int> get(int x) {
	vector<int> res;
	for (int i = 2; i <= x; i++) {
		if (x % i == 0) {
			res.push_back(i);
			while (x % i == 0) x /= i;
		}
	}
	return res;
}
int x1 = 1 << 30, n; 
int main() {
	scanf("%d", &n);
	vector<int> pn = get(n);
	for (auto t : pn) {
		printf("xxx %d\n", t);
		int k = n / t;
		for (int x2 = (k - 1) * t + 1; x2 <= n; x2++) {
			vector<int> pt = get(x2);
			for (auto t2 : pt) {
				printf("%d %d %d\n", x2, x1, t2);
				x1 = min(x1, (x2/t2 - 1) * t2 + 1);
			}
		}
	}
	printf("%d\n", x1);
	return 0;
}