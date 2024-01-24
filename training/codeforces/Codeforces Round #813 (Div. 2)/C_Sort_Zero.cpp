#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}

const int N = 1e5+10;
umap S;
int a[N];
void solve() {
    int n;
    std::cin >> n;
    S.clear();
    for(int i = 1;i <= n;i ++)
        std::cin >> a[i];
    int m = a[n];
    for(int i = n;i;i --) {
        if(a[i] > m) {
            // cout << a[i] << " ";
            S[a[i]] ++;
            a[i] = 0;
            m = 0;
        }
        else m = a[i];
    }
    for(int i = 1;i <= n;i ++) if(S.count(a[i]) == 1) a[i] = 0;
    m = a[n];

    // cout << "S: ";
    // for(auto c:S) {
    //     cout << c.first << " ";
    // }
    //     for(int i = 1;i <= n;  i ++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // cout << S.size() << endl;
    for(int i = n;i;i --) {
        if(a[i] > m) S[a[i]] ++, a[i] = 0, m = 0;
        else m = a[i];
    }
    cout << S.size() << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int T; cin >> T;
    // while(T --) {
    //     solve();
    // }
    ll t = (1<<31);
    cout << t << endl;
    return 0;
}
