#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e7+10;
struct KMP {
    int ne[N]; int len;
    char t[N];
    void clear() {
        len = ne[0] = ne[1] = 0;
    }
    // init string T
    void init(char *tt) {
        len = strlen(tt + 1);
        memcpy(t, tt, (len + 2) * sizeof(char));
        ne[1] = 0;
        for(int i = 2, j = 0;i <= len; i ++) {
            while(j > 0 && tt[i] != tt[j + 1]) j = ne[j];
            if(tt[i] == tt[j+1]) j ++;
            ne[i] = j;
        }
    }
    /* 求所有在s串中的start_pos. 如果first_only设置为true，则只返回第一个位置*/
    vector<int> match(char *s, bool first_only) {
        int lens = strlen(s + 1);
        vector<int> start_pos(0);
        start_pos.push_back(0);
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
char s[N], t[N];
void solve() {
    int n, k;
    cin >> n >> k;
    cin >> s + 1 >> t + 1;
    kmp.init(t);
    auto res = kmp.match(s, 0);
    ll ans = 0;
    for(int i = 1;i < res.size(); i ++) {
        ans += (res[i] - res[i - 1]) * (n - res[i] - k + 2);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}