
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

	for (int i = 1; i <= 1000; i++) {
		system("rand > t.in");
		system("ac < t.in > ac.txt");
		system("wa < t.in > wa.txt");
		if (system("fc ac.txt wa.txt")) {
			printf("Case %d is Wa!!\n", i);
			exit(0);
		} else {
			printf("Case %d is Ac!!\n", i);
		}
	}		
	return 0;
}
