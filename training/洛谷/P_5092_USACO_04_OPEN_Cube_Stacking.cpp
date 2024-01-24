#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 30010;
int n, p[N], d[N], sz[N];
// sz 记录每个集合的大小
// d 记录每个集合中的位置
int find(int x) {
    if(x != p[x]) {
        int root = find(p[x]);
        // d[p[x]] += d[x];
        d[x] += d[p[x]];
        p[x] = root;
    }
    return p[x];
}


void merge(int x, int y) {
    x = find(x);
    y = find(y);
    p[x] = y; d[x] = sz[y];
    sz[y] += sz[x];
}

void init() {
    for(int i = 1; i <= N; i ++) p[i] = i, sz[i] = 1;
}

void solve() {
    init();
    cin >> n;
    while(n --) {
        string op;
        cin >> op;
        if(op == "M") {
            int x, y;
            cin >> x >> y;
            if(find(x) != find(y))
                merge(x, y);
        }
        else {
            int x;
            cin >> x;
            find(x);
            cout << max(0, d[x]) << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
