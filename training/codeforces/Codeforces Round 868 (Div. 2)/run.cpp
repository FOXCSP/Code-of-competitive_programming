#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
#define P(T) pair<T, T>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
// head

int main() {
  for (int i = 1; i <= 1000; i++) {
		system("rand > in.txt");
		system("ac.exe < in.txt > ac.txt");
		system("wa.exe < in.txt > wa.txt");
		if (system("fc ac.txt wa.txt")) {
			printf("Case %d is Wa!\n", i);
			exit(0);
		}	else {
			printf("Case %d is Ac!\n", i);
		}
	}
  return 0;
}

/*
1
10 2
5 10
5 6

*/
