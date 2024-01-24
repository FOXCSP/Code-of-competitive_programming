#include <bits/stdc++.h>

using namespace std;

int main () {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max(min(a, d) * min(b, c), min(a, c) * min(b, d)) << endl;
	return 0;
}