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

const int N = 1000010;
int n, m;
string s, t;
int nxt[N];
int ls, lt;

void solve(int CaseT) {
    cin >> s >> t;
    ls = SZ(s);
    lt = SZ(t);
    s = "#" + s;
    t = "#" + t;

    // init() 
    nxt[0] = nxt[1] = 0;
    for (int i = 2, j = 0; i <= lt; i++) {
        while (j > 0 && t[i] != t[j + 1]) j = nxt[j];
        if (t[i] == t[j + 1]) j++;
        nxt[i] = j;
    }

    // match()
    vec<int> pos;
    for (int i = 1, j = 0; i <= ls; i++) {
        while (j > 0 && s[i] != t[j + 1]) j = nxt[j];
        if (s[i] == t[j + 1]) j++;
        if (j == lt) {
            pos.pb(i);
            j = nxt[j];
        }
    }
    cout << SZ(pos) << '\n';
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