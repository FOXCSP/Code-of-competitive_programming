#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], rd[N], cd[N], idx;
int group[N];
int n, m;
void add(int a,int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void bfs() {
    queue<int> q;
    for(int i = 1;i <= n;i ++) {
        if(rd[i] == 1 && cd[i] == 1) {
            q.push(i);
            group[i] = 1;
        }
    }
    
    while(q.size()) {
        int t = q.front(); q.pop();
        group[t] = 1;
        for(int i = h[t]; i != -1; i = ne[i]) {
            int to = e[i];
            -- rd[to]; -- cd[to];
            if(rd[to] == 1 && cd[to] == 1) q.push(to);
        }
    }
}

int col[N];
void dfs(int u, int c) {
    col[u] = c;
    for(int i = h[u]; ~i ; i = ne[i] ) {
        int j = e[i];
        if(group[j] && !col[j]) dfs(j, c); 
    }
}

int main () {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    std::cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1;i <= n;i ++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b), add(b, a);
        rd[b] ++, cd[a] ++;
        rd[a] ++, cd[b] ++;
    }
    bfs();
    cin >> m;
    int t = 0;
    // cout << "G:\n";
    // for(int i = 1;i <= n;i ++) {
    //     cout << group[i] << " \n"[i == n];
    // }

    for(int i = 1;i <= n; i ++)
        if(!group[i]) dfs(i, ++ t);
    // cout << "col\n";
    // for(int i = 1;i <= n;i ++) {
    //     cout << col[i] << " \n"[i == n];
    // }
    while(m --) {
        int a, b;
        cin >> a >> b;
        if(col[a] == col[b]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

/*
先求出来环的集合和非环的集合
在以 环上点 为起点 进行 dfs 染色
*/