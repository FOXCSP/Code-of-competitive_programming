#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define FOR(x, l, r) for(int x = l;x <= r; x ++)
#define FRO(x, r, l) for(int x = r;x >= l; x --)
#define For(x, l, r) for(int x = l;x < r;  x ++)
#define pb push_back
#define rp (p<<1|1)
#define lp (p<<1)
#define endl '\n'
#define fi first
#define se second
// #define int long long

using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 500010;
int a[N], b[N], n;

void solve() {
    scanf("%d", &n);
    for(int i = 1;i <= n; i ++) scanf("%d", a + i);
    pii c1 = {0, 0}, c2 = {0, 0};
    for(int i = 1;i <= n; i ++) {
        scanf("%d", b + i);
        if(a[i] == b[i]) c1.fi ++;
        else c1.se ++;
        if(a[n - i + 1] == b[i]) c2.fi ++;
        else c2.se ++;
    }
    // cout << c1.fi << " " << c2.fi << endl;
    if(c1.fi >= c2.fi){
        printf("%d\n", c1.se);
    }
    else printf("%d\n", c2.se + 1);
}

int main()
{
    solve();
    return 0;
}
