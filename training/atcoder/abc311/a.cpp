#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 200010;
const ll mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') a++;
		if (s[i] == 'B') b++;
		if (s[i] == 'C') c++;
		if (a && b && c) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
	return 0;
}
