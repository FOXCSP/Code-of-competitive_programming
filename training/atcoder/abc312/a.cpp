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

	string s;
	cin >> s;
	if (s == "ACE" || s == "BDF" || s == "CEG" || s == "DFA" || s == "EGB"
		|| s == "FAC" || s == "GBD") {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	
	return 0;
}
