#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e6 + 10;
int ne[N];
int lent, lens;
char T[N];
void init(char *t) {
    lent = strlen(t + 1);
    memcpy(T, t, (lent + 2) * sizeof(char));
    ne[0] = ne[1] = 0;
    for(int i = 2, j = 0; i <= lent; i ++) {
        while(j > 0 && t[i] != t[j + 1]) j = ne[j];
        if(t[i] == t[j + 1]) j ++;
        ne[i] = j;
    }
}
vector<int> match(char *s) {
    lens = strlen(s + 1);
    vector<int> ret(0);
    for(int i = 1, j = 0; i <= lens; i ++) {
        while(j > 0 && (j == lent || s[i] != T[j + 1])) j = ne[j];
        if(s[i] == T[j + 1]) j ++;
        if(j == lent) {
            ret.push_back(i - lent + 1);
            j = ne[j];
        }
    }
    return ret;
}
char s[N];
void solve() {
    cin >> s + 1;
    init(s);
    int a = ne[lent];
    char t[a + 2];
    for(int i = 1;i <= a;i ++) {
        t[i] = s[i];
    }
    t[a + 1] = '\0';
    init(t);
    // cout << a << " "  << t + 1 << endl;
    auto res = match(s);
    // cout << s + 1 << endl;
    if(a == 0) cout << "Just a legend\n";
    else {
    // cout << res.size() <<endl;
        if(res.size() >= 3) cout << t + 1 << "\n";
        else {
            init(t);
            if(ne[lent] == 0) cout << "Just a legend\n";
            else {
                for(int i = 1;i <= ne[lent]; i ++) cout << s[i];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
