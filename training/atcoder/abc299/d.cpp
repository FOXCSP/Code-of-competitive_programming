#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p << 1)
#define rp (p << 1 | 1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--
P(int) c[200010];

/*
7
0011011
0000001
?3

1



*/
void solve(int CaseT) {
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        cout << "? " << mid << endl;
        int x;
        cin >> x;
        if (x == 0) l = mid;
        else r = mid;
        if (l + 1 == r) {
            cout << "! " << l << endl;
            return ;
        }
    }
}

int main() {
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