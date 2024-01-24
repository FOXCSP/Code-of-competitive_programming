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

	srand(unsigned(time(0)));
	cout << 1 << "\n";
	int  n = rand() % 20 + 1;
	cout << n << '\n';
	for (int i = 1; i <= n; i++) {
		int c = rand() % 20 + 1;
		cout << c << " ";
		for (int j = 1; j <= c; j++) {
			int x = rand() % 30;
			x -= 15;
			cout << x << " ";
		}
		cout << '\n';
	}
	return 0;
}
