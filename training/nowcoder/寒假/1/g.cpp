#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
using namespace std;

const int N = 100010;
map<int, int> pos;
int n, m, a[N];
int cnt[N][13], mx[N], id;
int c[N];

// void modify(int x, int y) {
//     for (; x <= n; x += x & -x) c[x] += y;
// }

// int query(int x) {
//     int s = 0;
//     for (; x; x -= x & -x) s += c[x];
//     return s;
// }

struct seg {
    int val, sum, tag;
    seg operator + (const seg& B) const {
        return seg{}
    }
} tr[N * 4];

void build()

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int x = a[i];
        cnt[i][0] = x;
        for (int j = 1; j <= 13; j++) {
            x = round(10 * sqrt(1.0 * x));
            cnt[now][j] = x;
            if (x == 99) {
                mx[now] = j;
                break;
            }
        }
    }
    while (m --) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            modify(l, k);
            modify(r + 1, -k);
        } else {
            int t = query(2);

            cout << t << '\n';
        }
    }
    return 0;
}
