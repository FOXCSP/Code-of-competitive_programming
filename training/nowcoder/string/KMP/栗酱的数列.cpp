#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 2e5+10;

int a[N], b[N];
int n, m, k;
int ca[N], cb[N];
struct KMP {
    int ne[N]; int len;
    int t[N];
    void clear() {
        len = ne[0] = ne[1] = 0;
    }
    // init string T
    void init(int tt[]) {
        len = m - 1;
        memcpy(t, tt, (len + 2) * sizeof (int));
        ne[1] = 0;
        for(int i = 2, j = 0;i <= len; i ++) {
            while(j > 0 && tt[i] != tt[j + 1]) j = ne[j];
            if(tt[i] == tt[j+1]) j ++;
            ne[i] = j;
        }
    }
    /* 求所有在s串中的start_pos. 如果first_only设置为true，则只返回第一个位置*/
    vector<int> match(int s[], bool first_only) {
        int lens = n - 1;
        vector<int> start_pos(0);
        for(int i = 1, j = 0; i <= lens; i ++) {
            while(j > 0 && (j == len || s[i] != t[j+1])) j = ne[j];
            if(s[i] == t[j+1]) j ++;
            if(j == len) {
                start_pos.push_back(i - len + 1);
                if(first_only) return start_pos;
                j = ne[j];
            }
        }
        return start_pos;
    }
    // 最长border
    void border() {
        for(int i = 1;i <= len;i ++) cout << ne[i] << " ";
        cout << '\n';
    }
}kmp;

void solve() {
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        ca[i - 1] = (a[i] - a[i - 1]) % k;
    }
    
    for(int i = 1; i <= m;i ++) {
        cin >> b[i];
        cb[i - 1] = (b[i - 1] - b[i]) % k;
    }

    for(int i = 1;i < n;i ++) ca[i] = (ca[i] + k) % k;
    for(int i = 1;i < m;i ++) cb[i] = (cb[i] + k) % k;

    kmp.clear();
    kmp.init(cb);
    auto res = kmp.match(ca, 0);
    cout << res.size() << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}