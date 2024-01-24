#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
vector<int> ans;
int mx = 0, cnt[N], a, b, m;
int main() {
	scanf("%d%d%d", &a, &b, &m);
	int last = 0;
	for (int i = 1; i <= b; i++) {
		last = (last + m) % i;
		// printf("xx: %d\n", last + 1);
		if (i >= a) {
			cnt[last+1]++;
			if (cnt[last+1] > mx) {
				mx = cnt[last+1];
				ans.clear();
				ans.push_back(last+1);
			} else if (mx == cnt[last+1]) {
				ans.push_back(last+1);
			}
		}
	}
	printf("%d\n", mx);
	for (auto c : ans) {
		printf("%d ", c);
	}
	return 0;
}