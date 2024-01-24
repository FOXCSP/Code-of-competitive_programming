#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n;
void solve() {
    cin >> n;
    pair<int,int> cnt = {0,0};
    for(int i = 1;i <= n; i ++) {
        int x; cin >> x;
        if(x & 1) cnt.fi ++;
        else cnt.se ++;
    }

    bool flag = 0;
    if(cnt.fi & 1) {
        int t = (cnt.fi - 1) / 2;
        if(t & 1 || cnt.se & 1) flag = 1;
    }
    else{
        int t = cnt.fi / 2;
        if(!(t&1)) flag = 1;
    }
    if(flag) cout << "Alice\n";
    else cout << "Bob\n";

}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int T;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
