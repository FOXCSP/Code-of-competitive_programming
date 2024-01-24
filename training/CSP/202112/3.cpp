#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;

const int mod = 929;
int mode;
string str;
vector<int> buff;
int get_mode(char x) {
	if (x >= 'A' && x <= 'Z') return 0;
	if (x >= 'a' && x <= 'z') return 1;
	if (x >= '0' && x <= '9') return 2;
}
char car[3] = {'A', 'a', '0'};
void Wr(char x) {
	while (1) {
		if (mode == get_mode(x)) {
			buff.pb(x - car[mode]);
			break;
		}
		if (mode == 0 && get_mode(x) == 1)  buff.pb(27);
		if (mode == 0 && get_mode(x) == 2)  buff.pb(28);
		if (mode == 1 && get_mode(x) == 0)  buff.pb(28), buff.pb(28);
		if (mode == 1 && get_mode(x) == 2)  buff.pb(28);
		if (mode == 2 && get_mode(x) == 0)  buff.pb(28);
		if (mode == 2 && get_mode(x) == 1)  buff.pb(27);
		mode = get_mode(x);
	}
}

int A[1010], B[1010], C[1010]; 

int w, s;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> w >> s;
	cin >> str;
	for (auto x : str) Wr(x);
	if (SZ(buff)&1) buff.pb(29);
	vector<int> New;
	for (int i = 0; i < SZ(buff); i += 2) {
		New.pb(buff[i] * 30 + buff[i + 1]);
	}
	
	int len = SZ(New);
	if (s != -1) len += 1 << (s + 1);
	len++;
	while (len % w != 0) New.pb(900), len++;
	buff.clear();
	buff.pb(len - (1 << (s + 1)));
	for (auto x : New) buff.pb(x);
	
	// Ð£ÑéÂë
	int k = 1 << (s + 1);
	
	k = 2;
	B[1] = 1, B[0] = -3;
	int x = 1, y = -9;
	for (int i = 2; i <= k; i++) {
		B[i] = x;
		for (int j = i - 1; j ; j--) {
			B[j] = B[j] * y + B[j - 1] * x;
			B[j] %= mod; 
		}
		B[0] *= y;
		B[0] %= mod;
		y *= 3;
		y %= mod;
	}
	
	int n = SZ(buff), xxx = 0;
	while (n) {
		A[k + (n - 1)] = buff[xxx++];
		n--;
	}
	
	
	
	return 0; 
} 
