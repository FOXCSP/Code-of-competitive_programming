#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 27, M = 1010;
int ch[N], B, L, n;
string str[M];
int ans, CH[N];
LL Hash(string s) {
	LL res = 0;
	for(int i = 0; i < s.size(); i ++) {
		res = res * (B + 1) + ch[s[i] - 'A' + 1]; // 从1开始映射
	}
	return res;
}
void debug();
LL res[M];
void update() {
	memset(res, 0, sizeof res);
	for(int i = 1; i <= n; i ++) {
		res[i] = Hash(str[i]);
	}
	sort(res + 1, res + n + 1);
	int cnt = 0; // 注意cnt求的是只出现一次的字符串
	for(int i = 1; i <= n;i ++) 
		if(res[i] != res[i - 1] && res[i] != res[i + 1]) 
			cnt ++;
	if(cnt >= ans) {
		ans = cnt; 
		memcpy(CH, ch, sizeof CH);
	}
}

int idx = 1;
void dfs(int step, int color) {
	if(step > L) {
		if(color >= B)  {
			// cout << idx << " case\n";
			// idx ++;
			// debug();
			// cout << "--\n";
			update();
		}
		return ;
	}
	if(step > 1 && color < B)	ch[step] = color + 1, dfs(step + 1, color + 1); // 第一个只能填1
	if(L - step >= B - color)	ch[step] = color, dfs(step + 1, color); // 未填颜色和未填长度
	ch[step] = 0;
}

void debug() {
	for(int i = 1;i <= L; i ++) cout << CH[i] << " \n"[i == L];
}

void solve() {
	cin >> B >> L >> n;
	for(int i = 1; i <= n; i ++ ) cin >> str[i];
	dfs(1, 1);
	cout << ans << '\n';
	CH[0] = CH[1];
	// debug();
	for(int i = 1;i <= L; i ++) {
		if(CH[i] != CH[i - 1]) cout << '\n';
		cout << char(i + 'A' - 1);
	}
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	solve();
	return 0;
}