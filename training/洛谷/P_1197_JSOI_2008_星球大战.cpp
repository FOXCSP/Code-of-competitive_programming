#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 2e5 + 10, M = 4e5+10;
int n, m;
int p[M];
vector<int> ball;
set<int> DIS;

int h[M], e[M], ne[M], idx;

void init() {
    memset(h, -1, sizeof h);
    for(int i = 0;i < n;i ++) p[i] = i;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int find(int x) {
    if(x != p[x]) return p[x] = find(p[x]);
    return p[x];
}

void solve() {
    cin >> n >> m;
    init();
    for(int i = 1;i <= m;i ++) {
        int a, b; cin >> a >> b;
        add(a, b), add(b, a);
    }

    int k; cin >> k;
    int tot = n - k;
    while(k --) {
        int a; cin >> a;
        ball.push_back(a);
        DIS.insert(a);
    }

    reverse(ball.begin(), ball.end());
    vector<int> res;

    for(int i = 0;i < n;i ++) {
        if(DIS.find(i) != DIS.end()) continue;
        for(int k = h[i]; k != -1; k = ne[k]) {
            if(DIS.find(e[k]) != DIS.end()) continue;
            int pa = find(i), pb = find(e[k]);
            if(pa != pb) {
                p[pb] = pa;
                tot --;
            }
        }
    }

    res.push_back(tot);
    for(auto d : ball) {
        DIS.erase(d);
        tot ++;
        // cout << "ball : " << d << endl;
        for(int i = h[d]; ~i ; i = ne[i]) {
            int j = e[i];
            if(DIS.find(j) != DIS.end()) continue;
            int pa = find(d), pb = find(j);
            if(pa != pb) {
                // cout << "add: " << d << " " << j << '\n';
                p[pb] = pa;
                tot --;
            }
        }
        res.push_back(tot);
    }

    for(int i = res.size() - 1; i >= 0; i --) {
        cout << res[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
