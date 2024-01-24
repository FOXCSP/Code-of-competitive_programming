#include <bits/stdc++.h>

using namespace std;
using PII = pair<int,int>;

const int N = 10010;
priority_queue<PII, vector<PII>, greater<PII> > heap;
int n, m;
struct op {
	int a, b, c;
	int func(int x) {
		return a * x * x + b * x + c;
	}
} num[N];
int cnt[N];
void get(int x) {
	for(int i = 1; i <= n; i ++)
		heap.push({num[i].func(x), i});
}
void solve() {
	cin >> n >> m;
	for(int i = 1;i <= n; i ++) {
		cin >> num[i].a >> num[i].b >> num[i].c;
	}
	get(1);
	for(int i = 1;i <= n; i ++) cnt[i] = 1;
	while(m --) {
		auto t = heap.top(); heap.pop();
		int x = t.first, y = t.second;
		cnt[y] ++; heap.push({num[y].func(cnt[y]), y});
		cout << x << " ";
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}