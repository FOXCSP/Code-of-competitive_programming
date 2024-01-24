#include <bits/stdc++.h>

using namespace std;

const int N = 35;
int a[N], n;

void dfs(int p) {
	if (p > n) return ; 
	dfs(p * 2);
	dfs(p * 2 + 1);
	cin >> a[p];
}

int main() {
	cin >> n;
	dfs(1);
	for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}