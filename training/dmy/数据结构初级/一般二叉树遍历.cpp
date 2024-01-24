#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p << 1)
#define rp (p << 1 | 1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--
const ll mod = 1e9 + 7;

int n;
int L[1025], R[1025];

void pre(int p) {
    cout << p << " ";
    if (L[p]) pre(L[p]);
    if (R[p]) pre(R[p]);
}

void mid(int p) {
    if (L[p]) mid(L[p]);
    cout << p << " ";
    if (R[p]) mid(R[p]);
}

void suf(int p) {
    if (L[p]) suf(L[p]);
    if (R[p]) suf(R[p]);
    cout << p << " ";
}

void solve(int CaseT) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
    }
    pre(1);
    cout << '\n';
    mid(1);
    cout << '\n';
    suf(1);
    cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int _;
	_ = 1;
	// cin >> _;
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}