#include <bits/stdc++.h>

using namespace std;
const int N = 1000010, M = 5e6;
vector<array<int, 2>> e;
int a[N], n, prime[N * 2], cnt, ans, col;
bool vis[N * 5], st[N];
void Pm() {
    for (int i = 2; i <= M; i++) {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && 1ll * i * prime[j] <= M; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int ttt[N];
int p[N];
int find(int x) {return (p[x] == x) ? x : p[x] = find(p[x]);}

bool check(int u, int v) {
    u = a[u], v = a[v];
    int t = __gcd(u, v);
    int x = 0;
    if (!vis[t]) return false;
    for(int i = 2;i <= t/i;i ++)
    {
        if (t % i == 0) {
            x++;
            while(t % i == 0) t /= i;
        }
        if (x == 2) return true;
    }
    if(t > 1) x++;
    return x >= 2;
};

int main() {
    Pm();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (check(u, v)) {
            e.push_back({u, v});
        }
    }
    for (int i = 0; i <= n; i++) p[i] = i, ttt[i] = 1;
    for (auto t : e) {
        int x = t[0], y = t[1];
        int px=find(x), py=find(y);
        if (px != py) {
            p[py] = px;
            ttt[px]+=ttt[py];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) ans = max(ans, ttt[i]);
    }
    printf("%d\n", ans);
    return 0;
}