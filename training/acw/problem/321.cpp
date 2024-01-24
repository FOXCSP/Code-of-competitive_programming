#include <bits/stdc++.h>

using namespace std;

const int N = 15, M = 9;
int n;
double f[M][M][M][M][M];
double s[M][M];
double X;

double get(int x1, int y1, int x2, int y2) {
	double sum = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] - X;
	return 1.0 * sum * sum / n;
} // 计算方差公式
double dp(int x1, int y1, int x2, int y2, int k) {
	double &x = f[x1][y1][x2][y2][k];
	if(x >= 0) return x; // 1 * 8 切 9 刀会死循环
	if(k == 1) return x = get(x1, y1, x2, y2);
	x = 1e9; 
	for(int i = x1; i < x2; i ++) {
		x = min(x, get(x1, y1, i, y2) + dp(i + 1, y1, x2, y2, k - 1));
		x = min(x, get(i + 1, y1, x2, y2) + dp(x1, y1, i, y2, k - 1));
	} // 横着切
	for(int i = y1; i < y2; i ++) {
		x = min(x, get(x1, y1, x2, i) + dp(x1, i + 1, x2, y2, k - 1));
		x = min(x, get(x1, i + 1, x2, y2) + dp(x1, y1, x2, i, k - 1));
	}
	return x;
}

void solve() {
	cin >> n;
	for(int i = 1;i <= 8;i ++)
		for(int j = 1; j <= 8; j ++) {
			cin >> s[i][j];
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	X = s[8][8] / n;
	memset(f, -1, sizeof f);
	printf("%.3lf\n", sqrt(dp(1, 1, 8, 8, n)));
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}