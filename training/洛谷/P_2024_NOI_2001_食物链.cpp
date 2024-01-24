#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 5e4+10;
int p[N * 3], n, k;

int find(int x) {
    if(x != p[x]) return p[x] = find(p[x]);
    return p[x];
}
int read() {
    char c = getchar(); int n = 0, f = 1;
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar();
    }
    return n * f;
}
void solve() {
    cin >> n >> k;
    int cnt = 0;
    for(int i = 1; i <= n*3+1;i ++) p[i] = i;
    while(k --) {
        int op, x, y;
        cin >> op >> x >> y;
        if(x > n || y > n) cnt ++;
        else {
            if(op == 1) {
                bool f = true;
                if(find(x) == find(y+n) || find(y) == find(x+n)) f = false;
                if(f) {
                    p[find(x)] = find(y);
                    p[find(x+n)] = find(y+n);
                    p[find(x+n+n)] = find(y+n+n);
                }
                else cnt ++;
            }
            else {
                if(find(x) != find(y) && find(y) != find(x+n)) {
                    p[find(y+n)] = find(x);
                    p[find(y+n+n)] = find(x+n);
                    p[find(y)] = find(x+n+n);
                }
                else cnt ++;
            }
        }
    }
    cout << cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
