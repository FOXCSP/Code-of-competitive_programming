#include <iostream>
#include <cstring>

using namespace std;

const int  N = 100010;

int c[N], a[N], n, m;

int query(int x) {
    int res = 0;
    for(; x; x -= x & -x) res += c[x];
    return res;
}

void add(int x, int y) {
    for(; x <= n; x += x & -x) c[x] += y;
}


void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n;i ++) {
        cin >> a[i];
    }
    while(m --) {
        int op, l, r;
        cin >> op;
        if(op == 1) {
            int k; 
            cin >> l >> r >> k;
            add(l, k), add(r + 1, -k);
        }
        else {
            int x; cin >> x;
            int ans = query(x);
            cout << ans + a[x] << "\n";
        }
    }
}


int main () {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}