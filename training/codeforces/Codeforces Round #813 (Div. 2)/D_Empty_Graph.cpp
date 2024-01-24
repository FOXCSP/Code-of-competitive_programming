#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}

const int N = 1e5+10;
int n, k;
bool check(vector<int> a, int dist, int t) {
    for(int i = 0;i < a.size(); i ++) 
        if(a[i] * 2 < dist) t --, a[i] = 1e9;
    if(t < 0) return false;
    if(t == 0) {
        for(int i = 0;i < a.size() - 1; i ++) {
            if(min(a[i], a[i+1]) >= dist) return true;
        }
    } 
    else if(t == 1) {
        return *max_element(a.begin(), a.end()) >= dist;
    }else return true;
    return false;
}
void solve() {
    vector<int> a;
    std::cin >> n >> k;
    for(int i = 1;i <= n;i ++) {
        int x; cin >> x;
        a.push_back(x);
    }
    int l = 1, r = 1e9;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(check(a, mid, k)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) {
        solve();
    }    
    return 0;
}
