#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define all(T) T.begin(), T.end()
#define pb push_back 
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	srand((unsigned(time(0))));
	for (int i = 1; i <= 100; i++) {
		printf("Case %d is:\n", i);
		system("rand > in.txt");
		system("f_p < in.txt > ac.txt");
		system("f < in.txt > wa.txt");
		if (system("fc ac.txt wa.txt")) {
			printf(" WA!\n");
			exit(0);
		} else {
			printf(" AC!\n");
		}
	}
	return 0;
} 
