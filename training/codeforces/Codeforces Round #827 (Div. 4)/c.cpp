#include <bits/stdc++.h>

using namespace std;

char g[10][10];
bool check(int x, int op) {
	if(op == 1) {
		for(int i = 2; i <= 8; i ++ )
			if(g[x][i] != g[x][i - 1])
				return false;
	}
	if(op == 2) {
		for(int i = 2; i <= 8; i ++ ) 
			if(g[i][x] != g[i - 1][x])
				return false;
	}
	return true;
}

void solve() {
	for(int i = 1; i <= 8; i ++)
		cin >> g[i] + 1;
	int a = 0, b = 0;
	for(int i = 1; i <= 8; i ++) {
		if(g[i][1] == 'R' && check(i, 1)) a ++;
	}
	for(int i = 1; i <= 8; i ++) {
		if(g[1][i] == 'B' && check(i, 2)) b ++;
	}
	if(a > b) cout << "R\n";
	else cout << "B\n";
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _; cin>>_; while(_--)solve();
	return 0;
}