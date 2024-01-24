#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int maxn = 1e5+10;
string str;
char ch[maxn<<1|1];
int lc[maxn<<1|1], N;
void init() {
    int n = str.size() - 1;
    ch[0] = '@', ch[n<<1|1] = '#', ch[n*2+2] = '\0';
    for(int i = n;i ; i --) ch[i*2] = str[i], ch[i*2 - 1] = '#';
    N = n * 2 + 1;
}

void manacher() {
    lc[1] = 1; int k = 1;
    for(int i = 2;i <= N;i ++) {
        int p = k + lc[k] - 1;
        if(i <= p) {
            lc[i] = min(lc[2 * k - i], p - i + 1);
        }
        else lc[i] = 1;
        while(ch[i + lc[i]] == ch[i - lc[i]]) lc[i] ++;
        if(i + lc[i] > k + lc[k]) k = i;
    }
}

void debug() {
    cout << ch << endl;
    for(int i = 1;i <= N; i ++) {
        cout << "lc[" << i << "]=" << lc[i] << endl; 
    }
}

void solve() {
    memset(lc, 0, sizeof lc);
    str = '0' + str;
    int n = str.size() - 1;
    init();
    manacher();
    string result = str.substr(1, n);
    // cout << "n : " << n << endl;
    // cout << "lc : " << lc[(1 + N) / 2] - 1 << endl;
    // debug();
    if(lc[(1 + N) / 2] - 1 == n) {
        cout << result << "\n";
    }
    else {
        int pos;
        for(int i = 1;i <= N;i ++) {
            if(i + lc[i] - 1 == N) {
                if(ch[i] == '#') {
                    int r = lc[i] / 2;
                    pos = i - 2 * r - 1;
                }
                else {
                    int r = lc[i] / 2 + (lc[i] % 2);
                    pos = i - 2 * r;
                }
                break;
            }
        }
        // pos = pos / 2 + 1;
        pos /= 2;
        // cout << pos << '\n';
        string p = str.substr(1, pos);
        reverse(p.begin(), p.end());
        result += p;
        cout << result << "\n";
    }
}

int main()
{
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    while(cin >> str) solve();
    return 0;
}
