#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 12, M = 1 << 10, K = 110;

int n, k;

vector<int> state; // 所有合法的状态
int id[M];

vector<int> head[M]; // 每一个状态可以转移的其他状态
int cnt[M]; // 每个状态中1的个数

ll f[N][K][M];

bool check(int state) {
    for(int i = 0; i < n; i++) 
        if((state >> i & 1) && (state >> i + 1 & 1))
            return false;
    return true;
}

int count(int state) {
    int res = 0;
    for(int i = 0; i < n;i ++) res += state >> i & 1;
    return res;
}

void solve() {
    cin >> n >> k;
    for(int i = 0;i < 1 << n; i ++) if(check(i)) {
        state.push_back(i);
        id[i] = state.size() - 1; // 存的是合法状态的下标
        cnt[i] = count(i); // 计算这个合法状态会中有几个数
    }
    for(int i = 0;i < state.size(); i ++)
        for(int j = 0; j < state.size(); j ++) {
            int a = state[i], b = state[j];
            if((a & b) == 0 && check(a|b))
                head[i].push_back(j);
        }
    f[0][0][0] = 1;
    for(int i = 1;i <= n + 1; i ++ )
        for(int j = 0;j <= k; j ++)
            for(int a = 0; a < state.size(); a ++)
                for(int b : head[a]) {
                    int c = cnt[state[a]];
                    if(j >= c)
                        f[i][j][a] += f[i - 1][j - c][b];
                }
    cout << f[n + 1][k][0] << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
