#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;

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
	return 0; 
} 
