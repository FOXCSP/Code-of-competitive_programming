#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned ll;
// #define int long long
// #define mid ((l + r) >> 1)
#define endl '\n'

inline ll read()
{
    ll x = 0, ch = getchar(), f = 1;
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -f;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

const int N = 1e6 + 5;

int n, T, Q;
vector<ull> a[N]; // 存储每个小串的 hash 值
int ans[N], R[N], sz[N];

// 只保留 [0 , (2 ^ 44) -1] 上的映射哈希
// 进行了总共 O(n) 次哈希 (1e5 级别)
// 出错率 M / times ? May be 1e-9 ?
// 双哈希应该稳定不会挂 
const ll M = (1LL << 44) - 1; // 10 ^ 13
mt19937_64 rnd(time(0));
ull toull[N];

ull hashT = 0;

void solve()
{
    n = read(), T = read(), Q = read();

    for (int i = 0; i <= 1e5; i++)
        toull[i] = (rnd() & M);

    for (int i = 1; i <= T; i++)
        hashT += toull[read()];

    for (int i = 1; i <= n; i++)
    {
        sz[i] = read();
        ull hash_cur = 0;
        a[i].push_back(0);
        for (int j = 1; j <= sz[i]; j++)
            a[i].push_back(hash_cur += toull[read()]);
    }

    int m = read();
    for (int i = 1; i <= m; i++)
        R[i] = read();

    // ans[i] 储存第 i 节点的最早满足条件的 step 时间
    memset(ans, 0x3f, sizeof(ans));
    queue<int> q; // 队列模拟
    ull curHash = 0;
    int step = 1, qsz = 0;
    while (true)
    {
        bool f = (qsz >= T); // 先一直加 , 直到 长度大于 T 后扫一遍即可
        for (int i = 1; i <= m; i++, step++)
        {
            int fr = R[(i - 1) % m + 1];
            // add self
            curHash += a[fr].back(), qsz += sz[fr], q.push(fr);

            while (qsz - sz[q.front()] >= T) // del front
                curHash -= a[q.front()].back(), qsz -= sz[q.front()], q.pop();

            // judge
            if (qsz >= T && curHash - a[q.front()][qsz - T] == hashT)
                ans[i] = min(ans[i], step);
        }
        if (f)
            break;
    }

    int cnt = 0;
    for (int i = 1; i <= m; i++)
        if (ans[i] != 0x3f3f3f3f && ans[i] < Q)
            cnt += (Q - ans[i]) / m + 1;

    cout << cnt << endl;
}

signed main()
{
    int tc = 1;
    // tc = read();
    while (tc--)
    {
        solve();
#ifdef sunyuheng365
        puts("-----------------");
#endif
    }
#ifdef sunyuheng365
    system("pause");
#endif
}