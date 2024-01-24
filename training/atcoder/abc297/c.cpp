#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define setdb cout<<fixed<<setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

void solve(int CaseT) {
    int n, m;
    cin >> n >> m;
    vec<string> str;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        str.pb(s);
    }
    for (int i = 0; i < SZ(str); i++) {
        for (int j = 0; j < SZ(str[i])-1; j++) {
            if (str[i][j] == 'T' && str[i][j + 1] == 'T') {
                str[i][j] = 'P';
                str[i][j+1] = 'C';
            }
        }
    }
    for (auto x : str) {
        cout << x << '\n';
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