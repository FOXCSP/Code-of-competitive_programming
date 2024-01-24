#include <bits/stdc++.h>
#define fi first
#define se second
// #define int long long
using namespace std;

using ll = long long;

/*<--code-->*/

const int N = 1e5 + 10;


void solve() {
    int a, b, x;
    cin >> a >> b >> x;
    int pa = a/x,pb = b/x;
    if(pa == 0) {
        if(2*x <= b) {
            cout << x << " " << 2*x << endl;
            return ;
        }
    }
    else {
        if(a%x == 0 && (pa+1)*x <= b) {
            cout << a << " " << (pa+1)*x << endl;
            return;
        }
        if(a%x != 0 && (pa+2)*x <= b) {
            cout << (pa+1)*x << " " << (pa+2)*x << endl;
            return ;
        }    
    }
    cout << -1 << endl;
}

int main () {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}

