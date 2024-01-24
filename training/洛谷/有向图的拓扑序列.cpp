#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}

const int N = 100010;
int n, m;
int h[N], w[N], e[N], ne[N], idx;
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int rnd[N];
vector<int> res;
void bfs() {
    queue<int> q;
    for(int i = 1;i <= n;i ++) {
        if(!rnd[i]) q.push({i});
    }

    while(q.size()) {
        int t = q.front(); q.pop();
        res.push_back(t);
        for(int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if(-- rnd[j] == 0) q.push(j);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 1; i <= m;i ++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        rnd[y] ++;
    }
    bfs();
    if(res.size() == n) {
        for(auto c : res) cout << c << " ";
        cout << endl;
    }
    else {
        cout << "-1" << endl;
    }
    return 0;
}
