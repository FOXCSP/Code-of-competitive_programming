// 注意要求的目标回文串的长度要求, 本题隐藏条件回文串必须为偶数
#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int MaxN = 3e7+10;
int lc[MaxN];
char ch[MaxN], s[MaxN];
int N;
void init(char *s){
    int n = strlen(s+1);
    ch[n*2 +1] = '#';
    ch[0] = '@';
    ch[n*2 +2] = '\0';
    for (int i=n;i>=1;i--){
        ch[i*2] = s[i];ch[i*2 -1] = '#';
    }
    N = 2*n + 1;
}
void manacher() {
    lc[1] = 1; int k = 1;
    for(int i = 1; i <= N ;i += 2) {
        int p = k + lc[k] - 1;
        if(i <= p) {
            lc[i] = min(lc[2*k - i], p - i + 1);
        }
        else { lc[i] = 1; }
        while (i-lc[i]>0 && i+lc[i]<=N && (ch[i-lc[i]]=='#' || ch[i+lc[i]]!=ch[i-lc[i]])) 
            lc[i]++;
        if(i + lc[i] > k + lc[k]) k = i;
    }
}
void debug() {
    printf("%s\n", ch);
    for(int i = 1;i <= N; i ++) {
        printf("lc[%d]=%d\n", i, lc[i]);
    }
}

int n;
void solve() {
    cin >> n;
    scanf("%s", s + 1);
    init(s);
    manacher();
    // debug();
    int ans = 0;
    for(int i = 1;i <= N;i += 2) {
        ans += lc[i]/2;
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
