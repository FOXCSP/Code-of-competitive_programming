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

const int N = 100010;
vec<int> e[N];
int n, m, dig[N];

int p[N];

int find(int x) {
    return x != p[x] ? p[x] = find(p[x]) : x;
}

int tot;
void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        p[px] = py;
        tot--;
    }
}

void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        p[i] = i;

    tot = n;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        dig[u]++;
        dig[v]++;
        merge(u, v);
    }
    int a = 0, b = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        if (dig[i] & 1) b++;
        if (dig[i] == 0) a++;
    }
    if (tot != a + 1 || (b != 0 && b != 2)) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
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