#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

int a[10] = {0, 1, 1, 2, 2 , 2, 1, 1};
void solve() {
    string s;
    cin >> s;
    s = " " + s;
    int len = s.size();
    for(int i = 1; i < len ; i ++) {
        if(s[i] == '0') {
            if(i == 7) a[1] --;
            if(i == 4) a[2] --;
            if(i == 2 || i == 8) a[3] --;
            if(i == 1 || i == 5) a[4] --;
            if(i == 3 || i == 9) a[5] --;
            if(i == 6) a[6] --;
            if(i == 10) a[7] --;
        }
    }
    int l = 1, r = 7;
    bool f1 = 0, f2 = 0;
    // for(int i = 1;i <= 7;i ++) cout << a[i] << " \n"[i == 7];
    if(s[1] == '0'){
        while(l < r) {
            if(!f1) {
                if(a[l] > 0) f1 = 1;
                l ++;
            }
            if(!f2) {
                if(a[r] > 0) f2 = 1;
                r --;
            }
            if(f1 && f2) break;
        }
        if(f1 && f2) {
            for(int i = l; i <= r; i ++) {
                if(a[i] == 0) {
                    cout << "Yes\n";
                    return ;
                }
            }
        }
    }
    cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
