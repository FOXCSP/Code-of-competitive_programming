#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

priority_queue<pii> heap;

int cnt[30];
void solve() {
    string s; cin >> s;
    for(int i = 0; i < s.size(); i ++ ) 
        cnt[s[i] - 'a'] ++;
    for(int i = 0;i < 26;i ++) 
        if(cnt[i]) heap.push({cnt[i], i});
    while(heap.size()) {
        auto t = heap.top(); heap.pop();
        int v = t.second, w = t.first;
        cout << char( v+'a');
        w --;
        if(!w) continue;
        if(heap.empty()) break;

        auto tt = heap.top(); heap.pop();
        int vv = tt.second, ww = tt.first;
        cout << char(vv + 'a');
        ww --;
        heap.push({w, v});
        if(ww) heap.push({ww, vv}); 
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
